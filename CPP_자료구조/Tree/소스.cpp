#include "Tree.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	Tree<int> T;
	//����
	T.Insert(10);
	T.Insert(5);
	T.Insert(3);
	T.Insert(7);
	T.Insert(15);
	T.Insert(13);
	T.Insert(11);
	T.Insert(12);
	T.Insert(30);
	T.Insert(25);
	T.Insert(33);
	T.Insert(20);
	T.Insert(27);
	T.Insert(22);
	//��ȸ
	T.PreOrder();
	T.InOrder();
	T.PostOrder();
	//����
	T.Delete(15);
	T.Delete(5);
	T.Delete(33);
	cout << endl << "15, 5, 33 ���� �� " << endl;
	T.PreOrder();
	T.InOrder();
	T.PostOrder();
	//����
	T.Release();
	cout << endl << endl;

	Tree<char> T2;
	//����
	T2.Insert('g');
	T2.Insert('d');
	T2.Insert('a');
	T2.Insert('f');
	T2.Insert('p');
	T2.Insert('j');
	T2.Insert('h');
	T2.Insert('i');
	T2.Insert('u');
	T2.Insert('r');
	T2.Insert('t');
	//��ȸ
	T2.PreOrder();
	T2.InOrder();
	T2.PostOrder();
	//����
	T2.Delete('a');
	cout << endl << "���� �� " << endl;
	T2.PreOrder();
	T2.InOrder();
	T2.PostOrder();
	//����
	T2.Release();
}

// �����Ҷ� ������ ����� ����Ʈ ����Ʈ�� �� �� ������ ���
// ����Ʈ�� �ִ밪 ����Ʈ or ����Ʈ�� �ּҰ� ����Ʈ�� ��ü�ؾ��Ѵ�.
// Ʈ�� ��Ģ�� ��Ű�� ���ؼ�