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
		cout << "���� �� �Է� :";
		cin >> start;
		cout << "�� �� �Է� :";
		cin >> end;
		if (start < 2 || start > 9)
			cout << "���۴��� �������� ����ϴ�." << endl;
		else if (end < 2 || end > 9)
			cout << "������ �������� ����ϴ�." << endl;
		else if (start >= end)
			cout << "���۴��� ���ܺ��� ũ�ų� �����ϴ�." << endl;
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
				cout << "======" << i << "��======" << "\t";
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