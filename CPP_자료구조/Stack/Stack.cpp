#include "Stack.h"

void Stack::Push(Top** top, int data)
{ //push�� ���ο� data�� ������ new_top�� �Ҵ��Ѵ�.
	Top* new_top = new Top;
	new_top->link = *top; // new_top�� �ڱ���������ü�� top�� ���� ��
	*top = new_top; // top�� new_top�� ����Ų��.
	new_top->data = data;
	cout << "push���� " << new_top->data << "�Է�" << endl;
}

void Stack::Pop(Top** top)
{
	Top* tmp = *top; // �Ҵ������� tmp�����Ϳ� ���� top�� �ְ�
	*top = tmp->link; // top�� ������ tmp�� ����Ű�� ������ �̵�.
	cout << "pop���� " << tmp->data << "����" << endl;
	delete tmp; // ����
}