#pragma once

#include <list>
#include <queue>
#include <sstream>
#include <iostream>
#include <ctime>
#include <random>
#include <exception>

#include "windows.h"

#ifdef VAPULA_EXPORTS
#define VAPULA_API __declspec(dllexport)
#else
#define VAPULA_API
#endif

namespace vapula
{
	//using namespace
	using std::list;
	using std::queue;
	using std::string;
	using std::wstring;
	using std::ostringstream;

	//define null
	#define null 0

	//define type alias
	typedef void* raw;
	typedef unsigned char byte;
	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;
	typedef float real32;
	typedef double real64;

	typedef char* pstr;
	typedef wchar_t* pwstr;
	typedef const char* pcstr;
	typedef const wchar_t* pcwstr;

	//define enum
	enum DataType
	{
		VF_DATA_RAW = 0,
		VF_DATA_VALUE = 1,
		VF_DATA_TEXT = 2
	}; //data type

	enum ValueType
	{
		VF_VALUE_INT8 = 1,
		VF_VALUE_INT16 = 2,
		VF_VALUE_INT32 = 3,
		VF_VALUE_INT64 = 4,
		VF_VALUE_UINT8 = 5,
		VF_VALUE_UINT16 = 6,
		VF_VALUE_UINT32 = 7,
		VF_VALUE_UINT64 = 8,
		VF_VALUE_REAL32 = 10,
		VF_VALUE_REAL64 = 11,
	}; //value type

	enum AccessMode
	{
		VF_ACCESS_IN = 0,
		VF_ACCESS_OUT = 1,
		VF_ACCESS_INOUT = 2
	}; //access mode

	enum State
	{
		VF_STATE_IDLE = 0,
		VF_STATE_QUEUE = 1,
		VF_STATE_BUSY_BACK = 2,
		VF_STATE_BUSY_FRONT = 3,
		VF_STATE_ROLLBACK = 4,
		VF_STATE_PAUSE = 5
	}; //context state

	enum ControlCode
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
		VF_RETURN_NULLTASK = 4,
		VF_RETURN_UNHANDLED = 5
	}; //context return code

	enum CoreObject
	{
		VF_CORE_UNKNOWN = 0,
		VF_CORE_DRIVER = 1,
		VF_CORE_LIBRARY = 2,
		VF_CORE_STACK = 3,
		VF_CORE_ASPECT = 4
	};

	//define error
	pcstr const _vf_err_0 = "invalid data type";
	pcstr const _vf_err_1 = "invalid access";
	pcstr const _vf_err_2 = "invalid invoke";
	pcstr const _vf_err_3 = "untrusted invoke";

	pcstr const _vf_bridge = "Vapula Bridge";
	pcstr const _vf_version = "2.1.4.0";
	uint32 const _vf_oem_cp = CP_OEMCP;
	uint32 const _vf_msg_cp = CP_UTF8;

	pcstr const _vf_fatal = "!!! FATAL ERROR !!!";

	uint32 const _vf_path_len = 1024;
}