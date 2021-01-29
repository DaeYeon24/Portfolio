#pragma once
#include <iostream>
#include <crtdbg.h>
#include <string>
#include <Windows.h>
using namespace std;

#define MAX 10
#define ID 2
#define PW 3

enum BOOT
{
	ON,
	OFF
};

enum LOGINSTATUS
{
	SUCCESS,
	FAIL,
	EXIT
};