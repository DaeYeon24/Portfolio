#include <iostream>
#include <string>
using namespace std;

class gugu
{
private:
	int start;
	int end;
public:
	void GetNum();
	void Showgugu();
};

void gugu::GetNum()
{
	while (1)
	{
		system("cls");
		cout << "시작 단 입력 :";
		cin >> start;
		cout << "끝 단 입력 :";
		cin >> end;
		if (start < 2 || start > 9)
			cout << "시작단이 범위에서 벗어납니다." << endl;
		else if (end < 2 || end > 9)
			cout << "끝단이 범위에서 벗어납니다." << endl;
		else if (start >= end)
			cout << "시작단이 끝단보다 크거나 같습니다." << endl;
		else
			break;
		system("pause");
	}
}

void gugu::Showgugu()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = start; i <= end; i++)
		{
			if (j == 0)
				cout << "======" << i << "단======" << "\t";
			else
				cout << "  " << i << " x " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
}

void main()
{
	gugu gu;
	gu.GetNum();
	gu.Showgugu();
}