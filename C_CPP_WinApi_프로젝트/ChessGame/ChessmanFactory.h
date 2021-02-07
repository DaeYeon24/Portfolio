#pragma once
#include "Chessman.h"

class ChessmanFactory
{
public:
	virtual Chessman* Create_Chessman() = 0;
};

class PawnFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};

class RookFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};

class KnightFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};

class BishopFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};

class QueenFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};

class KingFactory : public ChessmanFactory
{
public:
	Chessman* Create_Chessman() override;
};