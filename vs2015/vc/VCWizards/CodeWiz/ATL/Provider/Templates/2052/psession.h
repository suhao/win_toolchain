// [!output SESSION_HEADER] : [!output SESSION_CLASS] 的声明

#pragma once

#include "resource.h"       // 主符号
#include "[!output ROWSET_HEADER]"
#include <strsafe.h>

using namespace ATL;

class [!output SESSION_CLASS]TRSchemaRowset;
class [!output SESSION_CLASS]ColSchemaRowset;
class [!output SESSION_CLASS]PTSchemaRowset;


// [!output SESSION_CLASS]
[!if ATTRIBUTED]
[
	coclass,
	noncreatable,
	uuid("[!output CLSID_SESSION_REGISTRY_FORMAT]"),
	threading(apartment),
	registration_script("none")
]
[!endif]
class ATL_NO_VTABLE [!output SESSION_CLASS] : 
[!if !ATTRIBUTED]
	public CComObjectRootEx<CComSingleThreadModel>,
[!endif]
	public IGetDataSourceImpl<[!output SESSION_CLASS]>,
	public IOpenRowsetImpl<[!output SESSION_CLASS]>,
	public ISessionPropertiesImpl<[!output SESSION_CLASS]>,
	public IObjectWithSiteSessionImpl<[!output SESSION_CLASS]>,
	public IDBSchemaRowsetImpl<[!output SESSION_CLASS]>,
	public IDBCreateCommandImpl<[!output SESSION_CLASS], [!output COMMAND_CLASS]>
{
public:
	[!output SESSION_CLASS]()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return FInit();
	}
	
	void FinalRelease() 
	{
	}

	STDMETHOD(OpenRowset)(IUnknown *pUnk, DBID *pTID, DBID *pInID, REFIID riid,
					   ULONG cSets, DBPROPSET rgSets[], IUnknown **ppRowset)
	{
		[!output ROWSET_CLASS]* pRowset;
		return CreateRowset(pUnk, pTID, pInID, riid, cSets, rgSets, ppRowset, pRowset);
	}

	void SetRestrictions(ULONG cRestrictions, GUID* rguidSchema, ULONG* rgRestrictions)
	{
		for (ULONG l=0; l<cRestrictions; l++)
		{
			// 我们支持对表名称(但仅限于表名称)的限制
			if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))
				rgRestrictions[l] = 0x04;
			else if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_COLUMNS))
				rgRestrictions[l] = 0x04;
			else if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_PROVIDER_TYPES))
				rgRestrictions[l] = 0x00;
		}
	}

BEGIN_PROPSET_MAP([!output SESSION_CLASS])
	BEGIN_PROPERTY_SET(DBPROPSET_SESSION)
		PROPERTY_INFO_ENTRY(SESS_AUTOCOMMITISOLEVELS)
	END_PROPERTY_SET(DBPROPSET_SESSION)
END_PROPSET_MAP()

[!if !ATTRIBUTED]
BEGIN_COM_MAP([!output SESSION_CLASS])
	COM_INTERFACE_ENTRY(IGetDataSource)
	COM_INTERFACE_ENTRY(IOpenRowset)
	COM_INTERFACE_ENTRY(ISessionProperties)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IDBCreateCommand)
	COM_INTERFACE_ENTRY(IDBSchemaRowset)
END_COM_MAP()
[!endif]

BEGIN_SCHEMA_MAP([!output SESSION_CLASS])
	SCHEMA_ENTRY(DBSCHEMA_TABLES, [!output SESSION_CLASS]TRSchemaRowset)
	SCHEMA_ENTRY(DBSCHEMA_COLUMNS, [!output SESSION_CLASS]ColSchemaRowset)
	SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, [!output SESSION_CLASS]PTSchemaRowset)
END_SCHEMA_MAP()

};

class [!output SESSION_CLASS]TRSchemaRowset : 
	public CSchemaRowsetImpl< [!output SESSION_CLASS]TRSchemaRowset, CTABLESRow, [!output SESSION_CLASS]>
{
public:
BEGIN_PROPSET_MAP([!output SESSION_CLASS]TRSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(LONG* pcRowsAffected, ULONG, const VARIANT*)
	{
		C[!output SHORT_NAME]WindowsFile wf;
		CTABLESRow trData;
		HRESULT hr;
		hr = StringCchCopy(trData.m_szType,sizeof(trData.m_szType)/sizeof(trData.m_szType[0]),OLESTR("TABLE"));
		if (FAILED(hr))
			return E_FAIL;
		hr = StringCchCopy(trData.m_szDesc,sizeof(trData.m_szDesc)/sizeof(trData.m_szDesc[0]),OLESTR("目录表"));
		if (FAILED(hr))
			return E_FAIL;

		HANDLE hFile = INVALID_HANDLE_VALUE;
		TCHAR szDir[MAX_PATH + 1];
		TCHAR szWildcard[] = _T("\\*.*");
		DWORD cchWildcard = sizeof(szWildcard)/sizeof(szWildcard[0]);
		DWORD cbCurDir = GetCurrentDirectory(MAX_PATH - cchWildcard, szDir);
		if (!cbCurDir || cbCurDir >= (MAX_PATH - cchWildcard))
			return E_FAIL;
		hr = StringCchCat(szDir,sizeof(szDir)/sizeof(szDir[0]),szWildcard);
		if (FAILED(hr))
			return E_FAIL;
		hFile = FindFirstFile(szDir, &wf);
		if (hFile == INVALID_HANDLE_VALUE)
			return E_FAIL; // 用户没有 c:\ 驱动器
		FindClose(hFile);
		hr = StringCchCopyNW(trData.m_szTable,sizeof(trData.m_szTable)/sizeof(trData.m_szTable[0]),CT2WEX<MAX_PATH + 1>(szDir),SIZEOF_MEMBER(CTABLESRow, m_szTable));
		if (FAILED(hr))
			return E_FAIL;
		
		_ATLTRY
		{
			m_rgRowData.Add(trData);
		}
		_ATLCATCH( e )
		{
			_ATLDELETEEXCEPTION( e )
			return E_OUTOFMEMORY;
		}

		*pcRowsAffected = 1;
		return S_OK;
	}

	DBSTATUS GetDBStatus(CSimpleRow*, ATLCOLUMNINFO* pInfo)
	{
		if (pInfo->iOrdinal == 1 || pInfo->iOrdinal == 2)
			return DBSTATUS_S_ISNULL;
		return DBSTATUS_S_OK;
	}
};


class [!output SESSION_CLASS]ColSchemaRowset : 
	public CSchemaRowsetImpl< [!output SESSION_CLASS]ColSchemaRowset, CCOLUMNSRow, [!output SESSION_CLASS]>
{
public:
BEGIN_PROPSET_MAP([!output SESSION_CLASS]ColSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(LONG* pcRowsAffected, ULONG, const VARIANT*)
	{
		C[!output SHORT_NAME]WindowsFile wf;
		HANDLE hFile = INVALID_HANDLE_VALUE;
		TCHAR szDir[MAX_PATH + 1];
		TCHAR szWildcard[] = _T("\\*.*");
		DWORD cchWildcard = sizeof(szWildcard)/sizeof(szWildcard[0]);
		DWORD cbCurDir = GetCurrentDirectory(MAX_PATH - cchWildcard, szDir);
		if (!cbCurDir || cbCurDir >= (MAX_PATH - cchWildcard))
			return E_FAIL;
		HRESULT hr = StringCchCat(szDir,sizeof(szDir)/sizeof(szDir[0]),szWildcard);
		if (FAILED(hr))
			return E_FAIL;
		hFile = FindFirstFile(szDir, &wf);
		if (hFile == INVALID_HANDLE_VALUE)
			return E_FAIL; // 用户没有 c:\ 驱动器
		FindClose(hFile);// szDir 已获得表名称

		DBID dbid;
		memset(&dbid, 0, sizeof(DBID));
		CT2WEX<MAX_PATH + 1> wszDir(szDir);
		dbid.uName.pwszName = wszDir;
		dbid.eKind = DBKIND_NAME;
		return InitFromRowset < _RowsetArrayType > (m_rgRowData, &dbid, NULL, m_spUnkSite, pcRowsAffected);
	}
	DBSTATUS GetDBStatus(CSimpleRow*, ATLCOLUMNINFO* pInfo)
	{
		switch(pInfo->iOrdinal)
		{
		case 1:
		case 2:
		case 19:
		case 20:
		case 22:
		case 23:
		case 25:
		case 26:
			return DBSTATUS_S_ISNULL;
		default:
			return DBSTATUS_S_OK;
		}

	}
};

class [!output SESSION_CLASS]PTSchemaRowset : 
	public CSchemaRowsetImpl< [!output SESSION_CLASS]PTSchemaRowset, CPROVIDER_TYPERow, [!output SESSION_CLASS]>
{
public:
BEGIN_PROPSET_MAP([!output SESSION_CLASS]PTSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(LONG* /*pcRowsAffected*/, ULONG, const VARIANT*)
	{
		return S_OK;
	}
};

