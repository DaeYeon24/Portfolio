//#include "Login.h"
#include "Computer.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 209;
	Computer User_Computer;
	User_Computer.Main();
}