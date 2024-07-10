

#include "stdafx.h"
#include "T1546_015.h"
#include "Factory.h"

ULONG g_ServerLocks = 0;    // server locks; 
ULONG g_Components = 0;    // number of components;


STDAPI DllCanUnloadNow() {
	HRESULT rc = E_UNEXPECTED;
	if ((g_ServerLocks == 0) && (g_Components == 0)) rc = S_OK;
	else rc = S_FALSE;

	return rc;
};

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv) {
	HRESULT rc = E_UNEXPECTED;
	Factory* pF;

	if (clsid == CLSID_T1546_015) {
		if ((pF = new Factory()) == NULL)
			rc = E_OUTOFMEMORY;
		else {
			rc = pF->QueryInterface(iid, ppv);
			pF->Release();
		}
	}
	else {
		rc = CLASS_E_CLASSNOTAVAILABLE;
	}

	return rc;
};