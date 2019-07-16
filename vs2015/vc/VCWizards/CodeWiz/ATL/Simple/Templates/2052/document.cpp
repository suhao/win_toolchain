// [!output HANDLER_ATL_DOC_IMPL_FILE_TRIMMED] : [!output HANDLER_ATL_DOC_CLASS_NAME_TRIMMED] 的实现

#include "stdafx.h"
#include <propkey.h>
#include "[!output HANDLER_ATL_DOC_HEADER_FILE_TRIMMED]"

HRESULT [!output HANDLER_ATL_DOC_CLASS_NAME_TRIMMED]::LoadFromStream(IStream* pStream, DWORD grfMode)
{
	// 从流加载文档数据
	UNREFERENCED_PARAMETER(pStream);
	UNREFERENCED_PARAMETER(grfMode);
	return S_OK;
}

void [!output HANDLER_ATL_DOC_CLASS_NAME_TRIMMED]::InitializeSearchContent()
{
	// 根据文档数据将搜索内容初始化为以下值
	CString value = _T("test;content;");
	SetSearchContent(value);
}

void [!output HANDLER_ATL_DOC_CLASS_NAME_TRIMMED]::SetSearchContent(CString& value)
{
	// 将搜索内容分配给 PKEY_Search_Contents 键
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

void [!output HANDLER_ATL_DOC_CLASS_NAME_TRIMMED]::OnDrawThumbnail(HDC hDrawDC, LPRECT lprcBounds)
{
	HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(hDrawDC, lprcBounds, hDrawBrush);

	HFONT hStockFont = (HFONT) GetStockObject(DEFAULT_GUI_FONT);
	LOGFONT lf;

	GetObject(hStockFont, sizeof(LOGFONT), &lf);
	lf.lfHeight = 34;

	HFONT hDrawFont = CreateFontIndirect(&lf);
	HFONT hOldFont = (HFONT) SelectObject(hDrawDC, hDrawFont);

	CString strText = _T("TODO: implement thumbnail drawing here");
	DrawText(hDrawDC, strText, strText.GetLength(), lprcBounds, DT_CENTER | DT_WORDBREAK);

	SelectObject(hDrawDC, hDrawFont);
	SelectObject(hDrawDC, hOldFont);

	DeleteObject(hDrawBrush);
	DeleteObject(hDrawFont);
}
