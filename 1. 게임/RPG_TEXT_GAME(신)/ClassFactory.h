#pragma once
#include "JobClass.h"

class ClassFactory
{
public:
	virtual JobClass* CreateJobClass(JOB what) = 0;
};

class Class : public ClassFactory
{
public:
	virtual JobClass* CreateJobClass(JOB what);
};