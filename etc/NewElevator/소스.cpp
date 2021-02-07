#include "Elevator.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	Elevator E;
	Stack Elevator;
	E.SetElevator(&Elevator);
	E.DrawTower();
	E.DrawElevator(Elevator);
	E.DrawElevatorInfo(Elevator);
	E.MenuDraw();
	char ch;
	srand(time(NULL));
	while (TRUE)
	{
		switch (Elevator.Derection)
		{
		case DERECTION_WAIT:
			E.Input(&Elevator);
			E.DrawElevatorInfo(Elevator);
			break;
		case DERECTION_UP:
		case DERECTION_DOWN:
			if (kbhit())
				ch = getch();
			E.MoveElevator(&Elevator);
			break;
		}
	}
}