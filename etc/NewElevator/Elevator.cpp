#include "Elevator.h"

void Elevator::ErasePeople(int x, int y)
{
	gotoxy(x, y);
	printf("      ");
	gotoxy(x, y + 1);
	printf("      ");
	gotoxy(x, y + 2);
	printf("      ");
}

void Elevator::DrawPeople(int x, int y)
{
	gotoxy(x, y);
	printf("  ○  ");
	gotoxy(x, y + 1);
	printf("┌┼┘");
	gotoxy(x, y + 2);
	printf("┌┴┐");
}

void Elevator::DrawTower()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y == 0)
			{
				if (x == 0)
					printf("┌");
				else if (x == WIDTH - 1)
					printf("┐");
				else
					printf("─");
			}
			else if (y == HEIGHT - 1)
			{
				if (x == 0)
					printf("└");
				else if (x == WIDTH - 1)
					printf("┘");
				else
					printf("─");
			}
			else if (x == 0 || x == WIDTH - 1)
				printf("│");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void Elevator::Push(Stack* Elevator)
{
	int Count = 1;
	Elevator->CurCount++;
	if (Elevator->Head == NULL)
	{
		Elevator->Head = new People;
		Elevator->Head->Weight = (rand() % 31) + 50;
		Elevator->CurWeight += Elevator->Head->Weight;
		Elevator->Head->Name = Count;
		Elevator->Head->Next = NULL;
	}
	else
	{
		People* TmpPeople = Elevator->Head;
		Count++;
		while (TmpPeople->Next != NULL)
		{
			TmpPeople = TmpPeople->Next;
			Count++;
		}
		People* NewPeople = new People;
		NewPeople->Weight = (rand() % 31) + 50;
		Elevator->CurWeight += NewPeople->Weight;
		NewPeople->Name = Count;
		NewPeople->Next = NULL;
		TmpPeople->Next = NewPeople;
	}
}

void Elevator::Pop(Stack* Elevator)
{
	if (Elevator->CurCount == 1)
	{
		Elevator->CurWeight -= Elevator->Head->Weight;
		delete Elevator->Head;
		Elevator->Head = NULL;
		Elevator->CurCount--;
	}
	else if (Elevator->CurCount > 1)
	{
		People* TmpHead = Elevator->Head;
		while (1)
		{
			if (Elevator->Head->Next->Next != NULL)
				Elevator->Head = Elevator->Head->Next;
			else
				break;
		}
		Elevator->CurWeight -= Elevator->Head->Next->Weight;
		delete Elevator->Head->Next;
		Elevator->Head->Next = NULL;
		Elevator->Head = TmpHead;
		Elevator->CurCount--;
	}
}

void Elevator::EraseElevator(Stack Elevator)
{
	int x = POSITION_X * 2;
	gotoxy(x, Elevator.y);
	printf("  ");
	for (int i = 1; i < ELEVATOR_WIDTH; i++)
		printf("  ");
	printf("  ");
	for (int y = Elevator.y + 1; y <= ELEVATOR_HEIGHT; y++)
	{
		gotoxy(x, y);
		printf("  ");
		gotoxy(x + (ELEVATOR_WIDTH * 2), y);
		printf("  ");
	}
	gotoxy(x, Elevator.y + ELEVATOR_HEIGHT);
	printf("  ");
	for (int i = 1; i < ELEVATOR_WIDTH; i++)
		printf("  ");
	printf("  ");
	if (Elevator.Head != NULL)
		ErasePeople(POSITION_X * 2 + (ELEVATOR_WIDTH - 2), Elevator.y + (ELEVATOR_HEIGHT - 3));
}

void Elevator::DrawElevator(Stack Elevator)
{
	int x = POSITION_X * 2;
	gotoxy(x, Elevator.y);
	printf("┌");
	for (int i = 1; i < ELEVATOR_WIDTH; i++)
		printf("─");
	printf("┐");
	for (int y = Elevator.y + 1; y <= ELEVATOR_HEIGHT + Elevator.y; y++)
	{
		gotoxy(x, y);
		printf("│");
		gotoxy(x + (ELEVATOR_WIDTH * 2), y);
		printf("│");
	}
	gotoxy(x, Elevator.y + ELEVATOR_HEIGHT);
	printf("└");
	for (int i = 1; i < ELEVATOR_WIDTH; i++)
		printf("─");
	printf("┘");
	if (Elevator.Head != NULL)
		DrawPeople(POSITION_X * 2 + (ELEVATOR_WIDTH - 2), Elevator.y + (ELEVATOR_HEIGHT - 3));
	else
		ErasePeople(POSITION_X * 2 + (ELEVATOR_WIDTH - 2), Elevator.y + (ELEVATOR_HEIGHT - 3));
}

void Elevator::SetElevator(Stack* Elevator)
{
	Elevator->Head = NULL;
	Elevator->MaxCount = 7;
	Elevator->MaxWeight = 400.0f;
	Elevator->y = 1;
	Elevator->CurCount = 0;
	Elevator->CurWeight = 0;
	Elevator->Derection = DERECTION_WAIT;
}

void Elevator::DrawPeopleInfo(People* P, int y)
{
	if (P == NULL)
	{
		gotoxy(WIDTH * 2 + 2, y);
		printf("                                      ");
		return;
	}
	DrawPeopleInfo(P->Next, y + 1);
	gotoxy(WIDTH * 2 + 2, y);
	printf("%d사람 무게 : %d", P->Name, P->Weight);
}

void Elevator::DrawElevatorInfo(Stack Elevator)
{
	int y = 0;
	gotoxy(WIDTH * 2 + 2, y);
	printf("인원 현황( %d / %d )\t무게 현황(%d / %d)                   ", Elevator.CurCount, Elevator.MaxCount, Elevator.CurWeight, Elevator.MaxWeight);
	DrawPeopleInfo(Elevator.Head, y + 1);
}

void Elevator::MoveElevator(Stack* Elevator)
{
	if (clock() - Elevator->OldClock >= ELEVATOR_SPEED)
	{
		EraseElevator(*Elevator);
		if (Elevator->Derection == DERECTION_DOWN)
			Elevator->y++;
		else if (Elevator->Derection == DERECTION_UP)
			Elevator->y--;
		DrawElevator(*Elevator);
		if (Elevator->y >= HEIGHT - ELEVATOR_HEIGHT - 2 || Elevator->y <= 1)
		{
			int Count = Elevator->CurCount;
			for (int i = 0; i < Count; i++)
			{
				gotoxy(WIDTH * 2 + 2, 1 + i);
				printf("                                    ");
			}
			while (Elevator->Head != NULL)
				Pop(Elevator);
			Elevator->Derection = DERECTION_WAIT;
			ErasePeople(POSITION_X * 2 + (ELEVATOR_WIDTH - 2), Elevator->y + (ELEVATOR_HEIGHT - 3));
			DrawElevatorInfo(*Elevator);
		}
		Elevator->OldClock = clock();
	}
}

void Elevator::MenuDraw()
{
	gotoxy(0, HEIGHT + 1);
	printf("엘리베이터 조작");
	gotoxy(0, HEIGHT + 2);
	printf("1.인원 탑승");
	gotoxy(0, HEIGHT + 3);
	printf("2.인원 하차");
	gotoxy(0, HEIGHT + 4);
	printf("3.엘리베이터 가동");
	gotoxy(0, HEIGHT + 5);
	printf("입력 : ");
}

void Elevator::Input(Stack* Elevator)
{
	int Select;
	gotoxy(0, HEIGHT + 5);
	printf("                            ");
	gotoxy(0, HEIGHT + 5);
	printf("입력 : ");
	scanf("%d", &Select);
	switch (Select)
	{
	case 1:
		Push(Elevator);
		DrawElevator(*Elevator);
		break;
	case 2:
		Pop(Elevator);
		DrawElevator(*Elevator);
		break;
	case 3:
		if (Elevator->CurWeight <= Elevator->MaxWeight && Elevator->CurCount <= Elevator->MaxCount)
		{
			if (Elevator->y == 1)
				Elevator->Derection = DERECTION_DOWN;
			else
				Elevator->Derection = DERECTION_UP;
			Elevator->OldClock = clock();
		}
		break;
	}
}