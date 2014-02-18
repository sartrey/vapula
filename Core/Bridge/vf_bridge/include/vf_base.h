#pragma once

#pragma warning(disable:4251)
#pragma warning(disable:4275)

#include "vf_assist.h"
#include "vf_string.h"
#include "vf_debug.h"

namespace vapula
{
	//spin lock
	class VAPULA_API Lock : Uncopiable
	{
	private:
		uint64* _Core; //TRUE - Lock , FALSE - Unlock

	private:
		static Lock* _CtorLock;

	public:
		Lock();
		~Lock();

	public:
		static Lock* GetCtorLock();

	public:
		//capture lock
		void Enter();

		//release lock
		void Leave();
	};

	//can be set only once
	class VAPULA_API Once : Uncopiable
	{
	private:
		object _Data;
		object _Seal;

	public:
		Once();
		~Once();

	public:
		//test if can be set
		bool CanSet();

		//set value
		void Set(object data, uint32 size);

		//get value
		object Get();
	};

	//flag
	class VAPULA_API Flag : Uncopiable
	{
	private:
		Lock* _Lock;
		int _Value;

	public:
		Flag();
		~Flag();

	public:
		//enable flag
		void Enable(int flag);

		//disable flag
		void Disable(int flag);

		//valid flag
		bool Valid(int flag);
	};

	//get type unit
	VAPULA_API uint32 GetTypeUnit(int8 type);

	//generate local unique id
	VAPULA_API pcstr GetLUID(bool logo = false);

	//get Vapula core version
	VAPULA_API pcstr GetVersion();

	//show value by simple message box
	template<typename T>
	VAPULA_API void ShowMsgbox(T value)
	{
		ShowMsgbox(str::Value(value), _vf_bridge);
	}

	//show string by simple message box
	VAPULA_API void ShowMsgbox(pcstr value, pcstr caption);

	//get runtime directory
	VAPULA_API pcstr GetRuntimeDir();

	//get process directory
	VAPULA_API pcstr GetProcessDir();

	//get process name
	VAPULA_API pcstr GetProcessName();

	//get path directory
	VAPULA_API pcstr GetDirPath(pcstr path, bool isfile = false);

	//test if file can be opened as read
	VAPULA_API bool CanOpenRead(pcstr file);
}