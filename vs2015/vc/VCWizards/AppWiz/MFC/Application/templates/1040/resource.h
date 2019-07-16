//{{NO_DEPENDENCIES}}
// File di inclusione generato con Microsoft Visual C++.
// Usato da [!output RC_FILE_NAME]
//
[!if APP_TYPE_MDI || APP_TYPE_TABBED_MDI]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#define IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP		4
[!if MENUBAR_TOOLBAR || RIBBON_TOOLBAR]
#define IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_IP_256	5
[!endif]
#define IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_SRVR_EMB		6
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
#define IDR_[!output SAFE_DOC_TYPE_NAME]TYPE_CNTR_IP		7
[!endif]
[!else]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#define IDR_SRVR_INPLACE			4
[!if MENUBAR_TOOLBAR || RIBBON_TOOLBAR]
#define IDR_SRVR_INPLACE_256		5
[!endif]
#define IDR_SRVR_EMBEDDED			6
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
#define IDR_CNTR_INPLACE			7
[!endif]
[!endif]
[!if RIBBON_TOOLBAR]
#define IDR_PASTE_MENU				151
#define IDR_WINDOWS_MENU			152
[!endif]
#define IDD_ABOUTBOX				100
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#define IDD_[!output UPPER_CASE_SAFE_PROJECT_IDENTIFIER_NAME]_FORM			101
[!endif]
[!if CONTAINER || CONTAINER_SERVER || MINI_SERVER || FULL_SERVER || AUTOMATION || ACTIVEX_CONTROLS || OLEDB || ACCESSIBILITY || RIBBON_TOOLBAR]
#define IDP_OLE_INIT_FAILED			100
[!if MINI_SERVER]
#define IDP_USE_INSERT_OBJECT		101
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
#define IDP_FAILED_TO_CREATE		102
#define ID_CANCEL_EDIT_CNTR			32768
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#define ID_CANCEL_EDIT_SRVR			32769
[!endif]
[!endif]
[!if RIBBON_TOOLBAR]
#define ID_WRITE_PASTEASHYPERLINK	32770
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#define IDP_FAILED_OPEN_DATABASE	103
[!endif]
[!if SOCKETS]
#define IDP_SOCKETS_INIT_FAILED		104
[!endif]
[!if RIBBON_TOOLBAR]
#define IDB_WRITESMALL				110
#define IDB_WRITELARGE				111
#define IDB_MAIN					112
#define IDB_BUTTONS					113
#define IDB_FILELARGE				114
#define IDB_FILESMALL				115
[!endif]
[!if MENUBAR_TOOLBAR || RIBBON_TOOLBAR]
#define IDR_POPUP_EDIT				119
#define ID_STATUSBAR_PANE1			120
#define ID_STATUSBAR_PANE2			121
#define IDS_STATUS_PANE1			122
#define IDS_STATUS_PANE2			123
[!endif]
[!if MENUBAR_TOOLBAR]
#define IDS_TOOLBAR_STANDARD		124
#define IDS_TOOLBAR_CUSTOMIZE		125
#define ID_VIEW_CUSTOMIZE			126
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
#define ID_VIEW_ARRANGE				127
[!endif]
[!endif]
#define IDR_MAINFRAME				128
[!if MENUBAR_TOOLBAR || RIBBON_TOOLBAR]
#define IDR_MAINFRAME_256			129
[!endif]
#define IDR_[!output SAFE_DOC_TYPE_NAME]TYPE				130
[!if APP_TYPE_MDI || ADV_DOCKING_EXPLORER]
#define ID_WINDOW_MANAGER			131
[!endif]
[!if ADV_DOCKING_EXPLORER]
#define ID_VIEW_FILEVIEW			133
#define ID_VIEW_CLASSVIEW			134
#define ID_PROPERTIES				135
#define ID_OPEN						136
#define ID_OPEN_WITH				137
#define ID_DUMMY_COMPILE			138
#define ID_CLASS_ADD_MEMBER_FUNCTION	139
#define ID_CLASS_ADD_MEMBER_VARIABLE	140
#define ID_CLASS_DEFINITION			141
#define ID_CLASS_PROPERTIES			142
#define ID_NEW_FOLDER				143
#define ID_SORT_MENU				144
#define ID_SORTING_GROUPBYTYPE		145
#define ID_SORTING_SORTALPHABETIC	146
#define ID_SORTING_SORTBYTYPE		147
#define ID_SORTING_SORTBYACCESS		148
[!endif]
[!if ADV_DOCKING_OUTPUT]
#define ID_VIEW_OUTPUTWND			149
[!endif]
[!if ADV_DOCKING_PROPERTIES]
#define ID_VIEW_PROPERTIESWND		150
#define ID_SORTPROPERTIES			151
#define ID_PROPERTIES1				152
#define ID_PROPERTIES2				153
#define ID_EXPAND_ALL				154
[!endif]
[!if ADV_DOCKING_EXPLORER]
#define IDS_FILE_VIEW				155
#define IDS_CLASS_VIEW				156
[!endif]
[!if ADV_DOCKING_OUTPUT]
#define IDS_OUTPUT_WND				157
[!endif]
[!if ADV_DOCKING_PROPERTIES]
#define IDS_PROPERTIES_WND			158
[!endif]
[!if ADV_DOCKING_EXPLORER]
#define IDI_FILE_VIEW				161
#define IDI_FILE_VIEW_HC			162
#define IDI_CLASS_VIEW				163
#define IDI_CLASS_VIEW_HC			164
[!endif]
[!if ADV_DOCKING_OUTPUT]
#define IDI_OUTPUT_WND				165
#define IDI_OUTPUT_WND_HC			166
[!endif]
[!if ADV_DOCKING_PROPERTIES]
#define IDI_PROPERTIES_WND			167
#define IDI_PROPERTIES_WND_HC		168
[!endif]
[!if ADV_DOCKING_EXPLORER]
#define IDR_EXPLORER				169
#define IDB_EXPLORER_24				170
#define IDR_SORT					171
#define IDB_SORT_24					172
#define IDR_POPUP_SORT				173
#define IDR_POPUP_EXPLORER			174
#define IDB_FILE_VIEW				175
#define IDB_FILE_VIEW_24			176
#define IDB_CLASS_VIEW				177
#define IDB_CLASS_VIEW_24			178
#define IDR_MENU_IMAGES				179
#define IDB_MENU_IMAGES_24			180
#define ID_TOOLS_MACRO				181
[!endif]
[!if ADV_DOCKING_OUTPUT]
#define IDR_OUTPUT_POPUP			182
[!endif]
[!if ADV_DOCKING_PROPERTIES]
#define IDR_PROPERTIES				183
#define IDB_PROPERTIES_HC			184
[!endif]
[!if ADV_DOCKING_NAVIGATION]
#define ID_VIEW_NAVIGATION			185
#define IDB_NAVIGATION_LARGE		186
#define IDB_NAVIGATION_LARGE_HC		187
#define IDB_PAGES					188
#define IDB_PAGES_HC				189
#define IDB_PAGES_SMALL				190
#define IDB_PAGES_SMALL_HC			191
[!endif]
[!if APP_TYPE_MTLD]
[!if !RIBBON_TOOLBAR]
#define IDS_CLOSE					195
[!endif]
[!endif]
[!if ENABLE_VISUAL_STYLE_SWITCHING]
#define IDR_THEME_MENU				200
#define ID_SET_STYLE				201
#define ID_VIEW_APPLOOK_WIN_2000	205
#define ID_VIEW_APPLOOK_OFF_XP		206
#define ID_VIEW_APPLOOK_WIN_XP		207
#define ID_VIEW_APPLOOK_OFF_2003	208
#define ID_VIEW_APPLOOK_VS_2005		209
#define ID_VIEW_APPLOOK_VS_2008		210
#define ID_VIEW_APPLOOK_OFF_2007_BLUE	215
#define ID_VIEW_APPLOOK_OFF_2007_BLACK	216
#define ID_VIEW_APPLOOK_OFF_2007_SILVER	217
#define ID_VIEW_APPLOOK_OFF_2007_AQUA	218
#define ID_VIEW_APPLOOK_WINDOWS_7	219
[!endif]
[!if ADV_DOCKING_CAPTION]
#define ID_TOOLS_OPTIONS			220
#define ID_VIEW_CAPTION_BAR			221
#define IDB_INFO					230
#define IDS_CAPTION_BUTTON			231
#define IDS_CAPTION_BUTTON_TIP		232
#define IDS_CAPTION_TEXT			233
#define IDS_CAPTION_IMAGE_TIP		234
#define IDS_CAPTION_IMAGE_TEXT		235
[!endif]
[!if ADV_DOCKING_NAVIGATION]
#define IDS_MYCALENDARS				250
#define IDS_CALENDAR				251
#define IDS_SHORTCUTS				252
#define IDS_FOLDERS					253
#define IDS_OUTLOOKBAR				258
[!endif]
[!if ADV_DOCKING_OUTPUT]
#define IDS_BUILD_TAB				300
#define IDS_DEBUG_TAB				301
#define IDS_FIND_TAB				302
[!endif]
[!if ADV_DOCKING_EXPLORER]
#define IDS_EXPLORER				305
[!endif]
[!if MENUBAR_TOOLBAR || RIBBON_TOOLBAR]
#define IDS_EDIT_MENU				306
[!endif]
[!if RIBBON_TOOLBAR]
#define IDR_RIBBON             			307
[!endif]

// Successivi valori predefiniti per i nuovi oggetti
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE	310
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		310
#define _APS_NEXT_COMMAND_VALUE		32771
#endif
#endif
