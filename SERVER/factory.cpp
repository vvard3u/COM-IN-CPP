#include "stdafx.h"
#include "factory.h"
#include "T1546_015.h"

Factory::Factory(void) : m_lref(1) {}
Factory::~Factory(void) {}


HRESULT STDMETHODCALLTYPE Factory::QueryInterface(REFIID riid, void** ppv)
{
	HRESULT rc = S_OK;
	if (riid == IID_IUnknown) *ppv = (IUnknown*)this;
	else if (riid == IID_IClassFactory) *ppv = (IClassFactory*)this;
	else rc = E_NOINTERFACE;
	if (rc == S_OK)
		this->AddRef();
	return rc;
}


ULONG STDMETHODCALLTYPE Factory::AddRef(void) {
	InterlockedIncrement(&m_lref);

	return this->m_lref;
}

ULONG STDMETHODCALLTYPE Factory::Release(void) {
	InterlockedDecrement(&m_lref);

	if (this->m_lref == 0) {
		//when there are not references to the object, we can delete it
		delete this;
		return 0;
	}
	else
		return this->m_lref;
}

HRESULT STDMETHODCALLTYPE Factory::CreateInstance(LPUNKNOWN pUnk, const IID& id, void** ppv) {
	HRESULT rc = E_UNEXPECTED;

	if (pUnk != NULL) rc = CLASS_E_NOAGGREGATION;
	else if (id == IID_IT1546_015_v1 || id == IID_IUnknown)
	{
		T1546_015* pA;
		if ((pA = new T1546_015()) == NULL)
			rc = E_OUTOFMEMORY;
		else
		{
			rc = pA->QueryInterface(id, ppv);
			pA->Release();
		}
		if (FAILED(rc)) {
			// initialization failed, delete component
			pA->Release();
			return rc;
		}
		rc = pA->QueryInterface(id, ppv);
		pA->Release();
		return rc;
	}
	return rc;
}

HRESULT STDMETHODCALLTYPE Factory::LockServer(BOOL fLock) {
	if (fLock) InterlockedIncrement((LONG*)&(g_ServerLocks));
	else InterlockedDecrement((LONG*)&(g_ServerLocks));

	return S_OK;
}
