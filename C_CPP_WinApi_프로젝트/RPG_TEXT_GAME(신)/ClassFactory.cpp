#include "ClassFactory.h"

JobClass* Class::CreateJobClass(JOB what)
{
    switch (what)
    {
    case KNIGHT: 
        return new Knight;
    case ARCHER:
        return new Archer;
    case WIZARD:
        return new Wizard;
    case LANCER:
        return new Lancer;
    }
}