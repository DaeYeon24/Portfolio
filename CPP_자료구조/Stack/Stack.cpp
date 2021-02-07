#include "Stack.h"

void Stack::Push(Top** top, int data)
{ //push로 새로운 data가 들어오면 new_top을 할당한다.
	Top* new_top = new Top;
	new_top->link = *top; // new_top의 자기참조구조체로 top을 연결 후
	*top = new_top; // top은 new_top을 가르킨다.
	new_top->data = data;
	cout << "push성공 " << new_top->data << "입력" << endl;
}

void Stack::Pop(Top** top)
{
	Top* tmp = *top; // 할당해제할 tmp포인터에 현재 top을 넣고
	*top = tmp->link; // top은 삭제될 tmp가 가르키는 번지로 이동.
	cout << "pop성공 " << tmp->data << "제거" << endl;
	delete tmp; // 삭제
}