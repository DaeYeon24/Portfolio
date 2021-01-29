#include "GameManager.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	char buf[256];
	sprintf_s(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2 + 1);
	system(buf);

	GameManager GM;
	GM.Title();
}