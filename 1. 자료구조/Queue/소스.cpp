#include "Queue.h"

void main()
{
	Queue Q;

	Q.EnQueue(10);
	Q.EnQueue(11);
	Q.EnQueue(12);
	Q.DeQueue();
	Q.DeQueue();
	Q.DeQueue();
}