#include "Manager.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 296;

	srand(time(NULL));
	
	Manager Game;
	Game.Title();
}