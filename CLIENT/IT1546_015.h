#pragma once
#include <objbase.h>

// {5219B44A-0874-449E-8611-B7080DBFA6AB}
static const GUID IID_IT1546_015_v1 =
{ 0x5219b44a, 0x874, 0x449e, { 0x86, 0x11, 0xb7, 0x8, 0xd, 0xbf, 0xa6, 0xab} };

interface IT1546_015 : IUnknown
{
	virtual HRESULT __stdcall malActivity() = 0;
};