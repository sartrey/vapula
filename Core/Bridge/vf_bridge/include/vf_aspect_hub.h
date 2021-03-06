#pragma once

#include "vf_base.h"

namespace vapula
{
	class Aspect;

	class AspectHub : Uncopiable
	{
	public:
		AspectHub();
		~AspectHub();

	private:
		Lock* _Lock;
		list<Aspect*> _Aspects;

	public:
		list<Aspect*>& GetInnerData();

	public:
		int Count();

		Aspect* Find(pcstr id);

		void Add(Aspect* aspect);

		void Remove(Aspect* aspect);

		void RemoveAll();
	};
}