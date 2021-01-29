#pragma once
#include "Çì´õ.h"

class Queue
{
private:
	Node* m_Front;
	Node* m_Rear;
public:
	Queue();
	void EnQueue(int data);
	void DeQueue();
};