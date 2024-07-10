#pragma once
#include <ObjBase.h>

HMODULE hT1546_015;

// {347CC716-94FA-412C-8B04-AAF0116CC8F0}
GUID CLSID_T1546_015 =
{ 0xDEADBEEF, 0xFACE, 0xFACE, {0xFA, 0xCE, 0xDE, 0xAD, 0xBE, 0xEF, 0xFA, 0xCE} };


const WCHAR FName[] = L"T1546_015 COM";
const WCHAR VerInd[] = L"T1546_015.Component";
const WCHAR ProgId[] = L"T1546_015.Component.3";


//extern "C"  __declspec(dllexport) HRESULT DllInstall(char* s);
//extern "C"  __declspec(dllexport) HRESULT DllRegisterServer();
//extern "C"  __declspec(dllexport) HRESULT DllUnregisterServer();
STDAPI DllInstall(char* s);
STDAPI DllRegisterServer();
STDAPI DllUnregisterServer();
// This function will register a component in the Registry.
// The component calls this function from its DllRegisterServer function.
HRESULT RegisterServer(HMODULE hModule,
    const CLSID& clsid,
    const WCHAR* szFriendlyName,
    const WCHAR* szVerIndProgID,
    const WCHAR* szProgID);

// This function will unregister a component.  Components
// call this function from their DllUnregisterServer function.
HRESULT UnregisterServer(const CLSID& clsid,
    const WCHAR* szVerIndProgID,
    const WCHAR* szProgID);