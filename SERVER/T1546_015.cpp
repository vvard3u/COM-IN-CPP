#include "T1546_015.h"
#include "stdafx.h"

extern ULONG g_Components;

T1546_015::T1546_015(void) : m_lref(1), myCom(NULL)
{
    InterlockedIncrement(reinterpret_cast<LONG*>(&g_Components));
}

T1546_015::~T1546_015(void)
{
    InterlockedDecrement(reinterpret_cast<LONG*>(&g_Components));
}

HRESULT STDMETHODCALLTYPE T1546_015::QueryInterface(REFIID riid, void** ppv) {
	HRESULT rc = S_OK;
	*ppv = NULL;

	if (riid == IID_IUnknown) *ppv = (IT1546_015*)this;
	else if (riid == IID_IT1546_015_v1) *ppv = (IT1546_015*)this;
	else rc = E_NOINTERFACE;

	if (rc == S_OK) this->AddRef();

	return rc;
}

ULONG   STDMETHODCALLTYPE T1546_015::AddRef(void) {
	InterlockedIncrement(&m_lref);
	return this->m_lref;
}

ULONG   STDMETHODCALLTYPE T1546_015::Release(void) {
	InterlockedDecrement(&m_lref);

	if (m_lref == 0) {

		this->myCom->Release();
		delete this;
		return 0;
	}
	else
		return this->m_lref;
}


HRESULT STDMETHODCALLTYPE T1546_015::malActivity(void)
{
    std::string title = "Will COM Hijacking work?";
    std::string msg = "Let's find out the answer! Follow guide for more!";
    MessageBoxA(0, msg.c_str(), title.c_str(), MB_OKCANCEL);
    return S_OK;
}


