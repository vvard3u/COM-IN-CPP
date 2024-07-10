#include <iostream>
#include <Windows.h>
#include "IT1546_015.h"

// Ensure that you link against the appropriate libraries
#pragma comment(lib, "Ole32.lib")
static const GUID CLSID_T1546_015 =
{ 0xDEADBEEF, 0xFACE, 0xFACE, {0xFA, 0xCE, 0xDE, 0xAD, 0xBE, 0xEF, 0xFA, 0xCE} };
int main()
{
    // Initialize COM library
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        std::cout << "Failed to initialize COM library." << std::endl;
        return 1;
    }

    // Create an instance of your COM object
    IT1546_015* pMyCom = NULL;
    hr = CoCreateInstance(CLSID_T1546_015, NULL, CLSCTX_INPROC_SERVER, IID_IT1546_015_v1, (void**)&pMyCom);

    if (FAILED(hr))
    {
        std::cout << "Failed to create COM object instance." << std::endl;
        CoUninitialize();
        return 1;
    }

    // Use the COM object
    hr = pMyCom->malActivity();
    if (SUCCEEDED(hr))
    {
        std::cout << "COM object method malActivity() executed successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to execute COM object method malActivity()." << std::endl;
    }

    // Release the COM object
    pMyCom->Release();

    // Uninitialize COM library
    CoUninitialize();

    return 0;
}
