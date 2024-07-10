#pragma once
#include <objbase.h>

extern ULONG g_ServerLocks;

class Factory : IClassFactory
{
protected:
	long m_lref;

public:
	Factory(void);
	~Factory(void);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);

	virtual HRESULT STDMETHODCALLTYPE CreateInstance(LPUNKNOWN pUnk, const IID& id, void** ppv);
	virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL flock);


};