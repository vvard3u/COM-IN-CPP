#include "IT1546_015.h"
// CLSID {DEADBEEF-FACE-FACE-FACE-DEADBEEFFACE}
static const GUID CLSID_T1546_015 = 
{ 0xDEADBEEF, 0xFACE, 0xFACE, {0xFA, 0xCE, 0xDE, 0xAD, 0xBE, 0xEF, 0xFA, 0xCE} };
class T1546_015 : public IT1546_015
{
private:
	IT1546_015* myCom;

protected:
	long m_lref;
public:
	T1546_015(void);
	~T1546_015(void);
	// Iunknown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);

	// IT1546_015
	virtual HRESULT STDMETHODCALLTYPE malActivity();

};


