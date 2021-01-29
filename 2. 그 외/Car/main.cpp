#include "Manager.h"
#include<crtdbg.h>
void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 979;

	Manager M1;
	
	M1.GogoRabbit();
	return;
}
