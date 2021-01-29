#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define ID 2
#define PW 3

typedef struct User
{
	string id;
	string pw;
	string nn;
	int age;
	string pn;
	int mileage;
}User;

void Join_InPut_Check(User* user, int IDorPW)
{
	string input;
	string pw_check;
	int input_length;
	bool essential = false;
	bool Letter;
	bool LetterCount;
	while (1)
	{
		system("cls");
		if (IDorPW == ID)
		{
			essential = true;
			cout << "���̵� �Է�(3���� �̻�, �ѱ� X) : ";
		}
		else if (IDorPW == PW)
			cout << "�н����� �Է�(8���� �̻�, �ѱ� X, ���� �ʼ�) : ";
		cin >> input;
		input_length = input.length();
		if (IDorPW == ID && input.length() < 3 || IDorPW == PW && input.length() < 8)
		{
			LetterCount = false;
			cout << "�Է� ���� �����ϴ�." << endl;
		}
		else
			LetterCount = true;
		for (int i = 0; i < input_length; i++)
		{
			if (IDorPW == PW && input[i] >= '0' && input[i] <= '9')
				essential = true;
			if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z' || input[i] >= '0' && input[i] <= '9')
				Letter = true;
			else
			{
				Letter = false;
				break;
			}
		}
		if (essential == false)
			cout << "���ڸ� �����ؾ��մϴ�." << endl;
		if (Letter == false)
			cout << "�������� �ۼ��ϼ���." << endl;
		if (Letter == false || LetterCount == false || essential == false)
		{
			system("pause");
			continue;
		}
		if (IDorPW == PW)
		{
			cout << "�н����� Ȯ�� : ";
			cin >> pw_check;
			if (pw_check != input)
			{
				cout << "Ȯ���� �н����尡 ��ġ���� �ʽ��ϴ�." << endl;
				system("pause");
				continue;
			}
			user->pw = input; // (*user).pw = input;
			return;
		}
		user->id = input; // 	(*user).id = input;
		return;
	}
}

void Join(User* user)
{
	system("cls");
	Join_InPut_Check(user, ID);
	Join_InPut_Check(user, PW);
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> user->nn;
	cout << "���� �Է� : ";
	cin >> user->age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> user->pn;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	user->mileage = 1000;
	return;
}
void ShowUser(User* user)
{
	cout << "==============ȸ�� ����==============" << endl;
	cout << "ID : " << user->id << "\t�г��� : " << user->nn << endl;
	cout << "���� : " << user->age << "\t�޴��� ��ȣ : " << user->pn << endl;
	cout << "���ϸ��� : " << user->mileage << endl;
	cout << "=====================================" << endl;

}

void AlterUser(User* user)
{
	int select;
	string Last_nn;
	int Last_age;
	string Last_pn;
	while (1)
	{
		system("cls");
		ShowUser(user);
		cout << "  1. �г��� ����" << endl;
		cout << "  2. ���� ����" << endl;
		cout << "  3. �޴��� ��ȣ ����" << endl;
		cout << "  4. ���ư���" << endl;
		cout << "�Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			Last_nn = user->nn;
			cout << "���� �г��� : " << user->nn << endl;
			cout << "������ �г��� �Է� : ";
			cin >> user->nn;
			cout << Last_nn << " -> " << user->nn << endl;
			break;
		case 2:
			Last_age = user->age;
			cout << "���� ���� : " << user->age << endl;
			cout << "������ ���� �Է� : ";
			cin >> user->age;
			cout << Last_age << " -> " << user->age << endl;
			break;
		case 3:
			Last_pn = user->pn;
			cout << "���� �޴��� ��ȣ : " << user->nn << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> user->pn;
			cout << Last_pn << " -> " << user->pn << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}

void UserMenu(User* user)
{
	int select;
	while (1)
	{
		system("cls");
		cout << "======Menu======" << endl;
		cout << "  1. ȸ�� ����" << endl;
		cout << "  2. ȸ�� ���� ����" << endl;
		cout << "  3. �α׾ƿ�" << endl;
		cout << "�Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			ShowUser(user);
			system("pause");
			break;
		case 2:
			AlterUser(user);
			break;
		case 3:
			return;
		}
	}
}

bool Login_InPut_Check(User user, string id, string pw)
{
	bool check = false;
	if (id == user.id && pw == user.pw)
		check = true;
	return check;
} 

void Login(User user[], int Count)
{
	bool login_success;
	string input_id;
	string input_pw;
	while (1)
	{
		system("cls");
		cout << "���̵� �Է� : ";
		cin >> input_id;
		cout << "��й�ȣ �Է� : ";
		cin >> input_pw;
		for (int i = 0; i < Count; i++)
		{
			login_success = Login_InPut_Check(user[i], input_id, input_pw);
			if (login_success == true)
			{
				UserMenu(&user[i]);
				return;
			}
		}
		cout << "��ġ�ϴ� ���̵�� ��й�ȣ�� �����ϴ�." << endl;
		system("pause");
		continue;
	}
}

void main()
{
	User User_List[MAX]; // 10��
	int Count = 0;
	int Select;
	while (1)
	{
		system("cls");
		cout << "====Login====(ȸ�� ��[" << Count << "��])" << endl;
		cout << "  1. ȸ������" << endl;
		cout << "  2. �α���" << endl;
		cout << "  3. ����" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Join(&User_List[Count]);
			Count++;
			break;
		case 2:
			Login(User_List, Count);
			break;
		case 3:
			return;
		}
	}
}