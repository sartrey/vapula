#pragma once

#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <stdexcept>
#include <ctime>

#include "windows.h"

#ifdef VAPULA_EXPORTS
#define VAPULA_API __declspec(dllexport)
#else
#define VAPULA_API
#endif

namespace vapula
{
	//using namespace
	using std::vector;
	using std::string;
	using std::wstring;
	using std::ostringstream;
	using std::invalid_argument;
	using std::bad_exception;

	//define type
	typedef void* object;
	typedef unsigned char byte;
	typedef char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;
	typedef float real32;
	typedef double real64;

	typedef char* str8;
	typedef wchar_t* str16;
	typedef const char* cstr8;
	typedef const wchar_t* cstr16;

	#define null 0

	//define enum
	enum DataType
	{
		VF_DATA_OBJECT = 0,
		VF_DATA_INT8 = 1,
		VF_DATA_INT16 = 2,
		VF_DATA_INT32 = 3,
		VF_DATA_INT64 = 4,
		VF_DATA_UINT8 = 5,
		VF_DATA_UINT16 = 6,
		VF_DATA_UINT32 = 7,
		VF_DATA_UINT64 = 8,
		VF_DATA_REAL32 = 10,
		VF_DATA_REAL64 = 11,
		VF_DATA_BOOL = 20,
		VF_DATA_STRING = 21
	}; //envelope data type

	enum ParamMode
	{
		VF_PM_IN = 0,
		VF_PM_OUT = 1,
		VF_PM_INOUT = 2
	};

	enum State
	{
		VF_STATE_IDLE = 0,
		VF_STATE_BUSY_BACK = 1,
		VF_STATE_BUSY_FRONT = 2,
		VF_STATE_PAUSE = 3
	}; //context state

	enum CtrlCode
	{
		VF_CTRL_NULL = 0,
		VF_CTRL_PAUSE = 1,
		VF_CTRL_RESUME = 2,
		VF_CTRL_CANCEL = 3,
		VF_CTRL_RESTART = 4
	}; //context control code

	enum ReturnCode
	{
		VF_RETURN_ERROR = 0,
		VF_RETURN_NORMAL = 1,
		VF_RETURN_CANCEL = 2,
		VF_RETURN_TERMINATE = 3,
		VF_RETURN_NULLENTRY = 4,
		VF_RETURN_NULLTASK = 5,
	}; //context return code

	//define error
	cstr8 const _vf_err_0 = "invalid data type";
	cstr8 const _vf_err_1 = "access null param";
	cstr8 const _vf_err_2 = "invalid invoke";
	cstr8 const _vf_err_3 = "untrusted invoke";

	cstr8 const _vf_bridge = "Vapula Bridge";
	cstr8 const _vf_msg_cp = "utf8";

	const uint32 _vf_path_len = 1024;
}