#include "vf_dev_inv.h"
#include "vf_debug.h"

#include "windows.h"

using std::cin;
using std::cout;
using std::endl;

using namespace vapula;

void Assert(bool condition)
{
	if(condition) cout<<"[OK]"<<endl;
	else
	{
		cout<<"[Fail]"<<endl;
		system("pause");
		exit(0);
	}
}

void Test1(Library* lib)
{
	cout<<"[get invoker] ... ";
	Invoker* inv = lib->CreateInvoker("context");
	Assert(inv != NULL);

	cout<<"[invoke function context] ... ";
	Assert(inv->Start());

	Stack* stack = inv->GetStack();
	Context* ctx = stack->GetContext();
	while(ctx->GetCurrentState() != VF_STATE_IDLE)
	{
		float prog = ctx->GetProgress();
		if(prog > 10)
		{
			cout<<"[pause] progress:"<<prog<<endl;
			inv->Pause(50);
			break;
		}
		Sleep(50);
	}
	int step = 0;
	cout<<"has paused, wait for a moment"<<endl;
	while(step < 20)
	{
		step++;
		Sleep(50);
	}
	inv->Resume();
	float prog = ctx->GetProgress();
	cout<<"[resume] progress:"<<prog<<endl;
	while(ctx->GetCurrentState() != VF_STATE_IDLE) 
		Sleep(50);
	cout<<"finished"<<endl;
}

void Test2(Library* lib)
{
	cout<<"[get invoker] ... ";
	Invoker* inv = lib->CreateInvoker("math");
	Assert(inv != NULL);

	Stack* stack = inv->GetStack();
	Dataset* ds = stack->GetDataset();

	(*ds)[1]->WriteAt(12);
	(*ds)[2]->WriteAt(23);

	cout<<"[invoke function math] ... ";
	Assert(inv->Start());

	Context* ctx = stack->GetContext();
	while(ctx->GetCurrentState() != VF_STATE_IDLE) 
		Sleep(50);
	
	int result = (*ds)[3]->ReadAt<int>();
	cout<<"<valid> - out:"<<result<<endl;

	LARGE_INTEGER freq, t1, t2;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);
	for (int i=0;i<10000;i++)
	{
		(*ds)[1]->WriteAt(12);
		(*ds)[2]->WriteAt(23);
		inv->Start();
		while(ctx->GetCurrentState() != VF_STATE_IDLE) 
			Sleep(0);
		(*ds)[3]->ReadAt<int>();
	}
	QueryPerformanceCounter(&t2);
	cout<<"adv time:"<<(t2.QuadPart - t1.QuadPart) * 1000.0 / (float)freq.QuadPart<<" (ms)"<<endl;
	Clear(inv);
}

void Test3(Library* lib)
{
	cout<<"[get invoker] ... ";
	Invoker* inv = lib->CreateInvoker("output");
	Assert(inv != NULL);
	Stack* stack = inv->GetStack();

	Context* ctx = stack->GetContext();
	Dataset* ds = stack->GetDataset();

	cout<<"[invoke function output] ... ";
	Assert(inv->Start());
	while(ctx->GetCurrentState() != VF_STATE_IDLE)
		Sleep(50);
	ShowMsgbox((pcstr)(*ds)[1]->Read());
	Clear(inv);
}

void Test4(Library* lib)
{
	cout<<"[get invoker] ... ";
	Invoker* inv = lib->CreateInvoker("context2");
	Assert(inv != NULL);
	Stack* stack = inv->GetStack();

	Context* ctx = stack->GetContext();

	cout<<"[invoke function context2] ... ";
	Assert(inv->Start());
	while(ctx->GetCurrentState() != VF_STATE_IDLE)
	{
		cout<<ctx->GetProgress()<<endl;
		Sleep(50);
	}
	Clear(inv);
}

void Test5(Library* lib)
{
	cout<<"[load aspect]";
	Aspect* aspect = Aspect::Load("E:\\Projects\\vapula\\Core\\OutDir\\Debug\\aspect.xml");
	if (aspect == null)
		return;
	Weaver* weaver = Weaver::GetInstance();
	weaver->Link(aspect);
	Invoker* inv = lib->CreateInvoker("protect");
	inv->Start();
	Stack* stack = inv->GetStack();
	Context* ctx = stack->GetContext();
	while(ctx->GetCurrentState() != VF_STATE_IDLE)
		Sleep(50);
}

void Test6()
{
	int* data = new int[123];
	for (int i = 0; i < 123; i++)
		data[i] = i;
	pcstr str = RawToBase64(data, 123 * sizeof(int));
	cout << "data:" << str << endl;
	int* data2 = (int*)Base64ToRaw(str);
	delete str;
	cout << "data:" << data2[122] << endl;
}

void Test7()
{
	pcstr data = "-23";
	uint8 i = (uint8)atoi(data);
	cout << (uint32)i << endl;
}

int main()
{
	//link driver manually
	//actually you can load library directly
	DriverHub* drv_hub = DriverHub::GetInstance();
	cout<<"[register driver crt] ... ";
	Assert(drv_hub->Link("crt"));
	//cout<<"[register driver clr] ... ";
	//Assert(drv_hub->Link("clr"));

	cout<<"[load library] ... ";
	pcstr cs8_dir = GetProcessDir();
	string path = cs8_dir;
	path += "sample_lib.library";
	
	Library* lib = Library::Load(path.c_str());
	LibraryHub* lib_hub = LibraryHub::GetInstance();
	lib_hub->Link(lib);
	Assert(lib != NULL);

	cout<<"[mount library] ... ";
	Assert(lib->Mount());

	//Test1(lib);
	//Test2(lib);
	//Test3(lib);
	//Test4(lib);
	//Test5(lib);
	//Test6();
	Test7();

	cout<<"[unmount component]"<<endl;
	lib->Unmount();

	cout<<"[kick all driver]"<<endl;
	drv_hub->KickAll();

	//_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}