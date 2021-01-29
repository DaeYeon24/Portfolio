#include "Tree.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 399;

	Tree<int> T;
	//삽입
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
	//순회
	T.PreOrder();
	T.InOrder();
	T.PostOrder();
	//삭제
	T.Delete(15);
	T.Delete(5);
	T.Delete(33);
	cout << endl << "15, 5, 33 삭제 후 " << endl;
	T.PreOrder();
	T.InOrder();
	T.PostOrder();
	//종료
	T.Release();
	cout << endl << endl;

	Tree<char> T2;
	//삽입
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
	//순회
	T2.PreOrder();
	T2.InOrder();
	T2.PostOrder();
	//삭제
	T2.Delete('a');
	cout << endl << "삭제 후 " << endl;
	T2.PreOrder();
	T2.InOrder();
	T2.PostOrder();
	//종료
	T2.Release();
}

// 삭제할때 삭제할 노드의 레프트 라이트가 둘 다 존재할 경우
// 레프트의 최대값 라이트 or 라이트의 최소값 레프트를 대체해야한다.
// 트리 규칙을 지키기 위해서