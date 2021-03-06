#pragma once

#include "vf_crt.h"

using namespace vapula;

class DriverCRT: public Driver
{
public:
	DriverCRT();
	~DriverCRT();

public:
	pcstr GetRuntimeId();
	pcstr GetBinExt();
	Library* CreateLibrary();
	Task* CreateTask();
};

extern "C" __declspec(dllexport) Driver* GetDriverInstance();