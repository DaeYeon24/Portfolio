#include "Stack.h"

void main()
{
	Stack S1;
	Top* top = NULL;

	S1.Push(&top, 10);
	S1.Push(&top, 11);
	S1.Push(&top, 12);		
	S1.Push(&top, 13);
	S1.Push(&top, 14);
	S1.Push(&top, 15);
	S1.Pop(&top);
	S1.Pop(&top);
	S1.Pop(&top);
	S1.Pop(&top);
	S1.Pop(&top);
}