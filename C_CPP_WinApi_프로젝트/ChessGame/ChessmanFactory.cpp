#include "ChessmanFactory.h"

Chessman* PawnFactory::Create_Chessman()
{
	return new Pawn;
}

Chessman* RookFactory::Create_Chessman()
{
	return new Rook;
}

Chessman* KnightFactory::Create_Chessman()
{
	return new Knight;
}

Chessman* BishopFactory::Create_Chessman()
{
	return new Bishop;
}

Chessman* QueenFactory::Create_Chessman()
{
	return new Queen;
}

Chessman* KingFactory::Create_Chessman()
{
	return new King;
}