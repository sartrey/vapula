#pragma once

#include "vf_utility.h"

namespace vapula
{
	class Function;
	class Context;
	class Envelope;

	//stack
	class VAPULA_API Stack
	{
	public:
		Stack();
		~Stack();
	private:
		uint32 _StackId;
		Function* _Function;
		Context* _Context;
		Envelope* _Envelope;
	public:
		static Stack* GetInstance();
	public:
		//get stack id
		uint32 GetStackId();

		//set stack id
		void SetStackId(uint32 id);

		//get function
		Function* GetFunction();

		//set function
		void SetFunction(Function* func);

		//get context
		Context* GetContext();

		//set context
		void SetContext(Context* ctx);

		//get envelope
		Envelope* GetEnvelope();

		//{TI2} set envelope
		void SetEnvelope(Envelope* env);
	};

	//stack hub
	class VAPULA_API StackHub
	{
	private:
		StackHub();
	public:
		~StackHub();
	private:
		static StackHub* _Instance;
	public:
		static StackHub* GetInstance();
	private:
		Lock* _Lock;
		vector<Stack*> _Stacks;
	public:
		//get stack by id
		Stack* GetStack(uint32 id);
	public:
		//link stack
		bool Link(Stack* stack);

		//kick stack
		void Kick(Stack* stack);

		//kick all stacks
		void KickAll();

		//get count of linked stack
		int GetCount();
	};
}