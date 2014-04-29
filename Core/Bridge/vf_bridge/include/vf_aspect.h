#pragma once

#include "vf_base.h"

namespace vapula
{
	class Invoker;

	//aspect
	class VAPULA_API Aspect
	{
	private:
		pcstr _Id;
		pcstr _Contact;
		pcstr _LibraryId;
		pcstr _MethodId;
		uint8 _Mode;
	private:
		Invoker* _Invoker;

	public:
		Aspect();
		~Aspect();

	public:
		//load aspect by path
		static Aspect* Load(pcstr path);

	public:
		//get aspect id
		pcstr GetAspectId();

		//get aspect mode
		uint8 GetMode();

		//get key frame regex pattern
		pcstr GetContact();

		//get library id
		pcstr GetLibraryId();

		//get method id
		pcstr GetMethodId();

		//get invoker
		Invoker* GetInvoker();

		//test if frame match with contact
		bool TryMatch(pcstr frame);
	};
}