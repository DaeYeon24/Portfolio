#include <iostream>
#include <string>
using namespace std;

class square
{
private:
	int row;
	int col;
public:
	void GetRowCol();
	void Showsquare();
};

void square::GetRowCol()
{
	while (1)
	{
		system("cls");
		cout << "���� �Է� : ";
		cin >> row;
		cout << "���� �Է� : ";
		cin >> col;
		if (row < 1 || col < 1)
			cout << "���� ���� ���̰� 1���� �۽��ϴ�." << endl;
		else
			break;
		system("pause");
		continue;
	}
}

void square::Showsquare()
{
	for (int i = 0; i <= col; i++)
	{
		for (int j = 0; j <= row; j++)
		{
			if ((j != 0 && j != row) && (i == 0 || i == col))
				cout << "��";
			else if ((i != 0 && i != col) && (j == 0 || j == row))
				cout << "��";
			else if (i == 0 && j == 0)
				cout << "��";
			else if (i == 0 && j == row)
				cout << "��";
			else if (i == col && j == 0)
				cout << "��";
			else if (i == col && j == row)
				cout << "��";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void main()
{
	square s1;
	s1.GetRowCol();
	s1.Showsquare();
}