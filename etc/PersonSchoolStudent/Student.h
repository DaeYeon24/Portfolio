#pragma once
#include "Person.h"
#include "School.h"

class Student : public School, public Person
{
public:
	Student();
	~Student();
	void Display();
};

