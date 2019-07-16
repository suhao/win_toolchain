/*++

Copyright (c) Microsoft Corporation

Module Name:

    WdfGlobals.h

Abstract:

    This module contains globals definitions for the frameworks.

Environment:

    kernel mode only

Revision History:


--*/

#ifndef _WDFGLOBALS_H_
#define _WDFGLOBALS_H_



#ifdef __cplusplus
extern "C" {
#endif

#define WDF_DRIVER_GLOBALS_NAME_LEN (32)

typedef struct _WDF_DRIVER_GLOBALS {

    // backpointer to the handle for this driver
    WDFDRIVER Driver;

    // Flags indicated by the driver during create
    ULONG DriverFlags;

    // Tag generated by WDF for the driver.  Tag used by allocations made on
    // behalf of the driver by WDF.
    ULONG DriverTag;

    CHAR DriverName[WDF_DRIVER_GLOBALS_NAME_LEN];

    // If TRUE, the stub code will capture DriverObject->DriverUnload and insert
    // itself first in the unload chain.  If FALSE, DriverUnload is left alone
    // (but WDF will not be notified of unload and there will be no auto cleanup).
    BOOLEAN DisplaceDriverUnload;

} WDF_DRIVER_GLOBALS, *PWDF_DRIVER_GLOBALS;





#ifdef __cplusplus
}
#endif

#endif // _WDFGLOBALS_H_

