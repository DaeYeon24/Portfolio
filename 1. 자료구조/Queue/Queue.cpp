#include "Queue.h"

Queue::Queue()
{
	m_Front = NULL;
	m_Rear = NULL;
}

void Queue::EnQueue(int data)
{
	Node* new_node = new Node;
	if (m_Front == NULL)
		m_Front = new_node;
	else
		m_Rear->link = new_node;
	new_node->data = data;
	new_node->link = NULL;
	m_Rear = new_node;
	cout << "EnQueue���� ���� Front = " << m_Front->data << "���� Rear = " << m_Rear->data << endl;
}

void Queue::DeQueue()
{
	if (m_Front != NULL)
	{
		Node* tmp = m_Front;
		m_Front = tmp->link;
		cout << "DeQueue���� ��µ� �� = " << tmp->data;
		delete tmp;
		if(m_Front != NULL)
			cout << " ���� Front = " << m_Front->data << "���� Rear = " << m_Rear->data << endl;
	}
}