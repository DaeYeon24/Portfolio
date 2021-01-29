#include "Login.h"

Login::Login()
{
	m_iUser_Count = 0;
	for (int i = 0; i < MAX; i++)
		m_pUser_List[i] = NULL;
}

int Login::Menu()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "====Login====(ȸ�� ��[" << m_iUser_Count << "��])" << endl;
		cout << "  1. ȸ������" << endl;
		cout << "  2. �α���" << endl;
		cout << "  3. ����" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			m_pUser_List[m_iUser_Count] = new User;
			Join();
			m_iUser_Count++;
			break;
		case 2:
			if (LoginUser() == FAIL)
				break;
			else
				return SUCCESS;
		case 3:
			return EXIT;
		}
	}
}

void Login::Join_InPut_Check(int IDorPW)
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
			m_pUser_List[m_iUser_Count]->pw = input; // (*user).pw = input;
			return;
		}
		m_pUser_List[m_iUser_Count]->id = input; // 	(*user).id = input;
		return;
	}
}

void Login::Join()
{
	system("cls");
	Join_InPut_Check(ID);
	Join_InPut_Check(PW);
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> m_pUser_List[m_iUser_Count]->nn;
	cout << "���� �Է� : ";
	cin >> m_pUser_List[m_iUser_Count]->age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> m_pUser_List[m_iUser_Count]->pn;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	m_pUser_List[m_iUser_Count]->mileage = 1000;
	return;
}

void Login::ShowUser()
{
	cout << "==============ȸ�� ����==============" << endl;
	cout << "ID : " << m_pUser_List[m_iLogin_index]->id << "\t�г��� : " << m_pUser_List[m_iLogin_index]->nn << endl;
	cout << "���� : " << m_pUser_List[m_iLogin_index]->age << "\t�޴��� ��ȣ : " << m_pUser_List[m_iLogin_index]->pn << endl;
	cout << "���ϸ��� : " << m_pUser_List[m_iLogin_index]->mileage << endl;
	cout << "=====================================" << endl;

}

void Login::AlterUser()
{
	int select;
	string Last_nn;
	int Last_age;
	string Last_pn;
	while (1)
	{
		system("cls");
		ShowUser();
		cout << "  1. �г��� ����" << endl;
		cout << "  2. ���� ����" << endl;
		cout << "  3. �޴��� ��ȣ ����" << endl;
		cout << "  4. ���ư���" << endl;
		cout << "�Է� : ";
		cin >> select;
		switch (select)
		{
		case 1:
			Last_nn = m_pUser_List[m_iLogin_index]->nn;
			cout << "���� �г��� : " << m_pUser_List[m_iLogin_index]->nn << endl;
			cout << "������ �г��� �Է� : ";
			cin >> m_pUser_List[m_iLogin_index]->nn;
			cout << Last_nn << " -> " << m_pUser_List[m_iLogin_index]->nn << endl;
			break;
		case 2:
			Last_age = m_pUser_List[m_iLogin_index]->age;
			cout << "���� ���� : " << m_pUser_List[m_iLogin_index]->age << endl;
			cout << "������ ���� �Է� : ";
			cin >> m_pUser_List[m_iLogin_index]->age;
			cout << Last_age << " -> " << m_pUser_List[m_iLogin_index]->age << endl;
			break;
		case 3:
			Last_pn = m_pUser_List[m_iLogin_index]->pn;
			cout << "���� �޴��� ��ȣ : " << m_pUser_List[m_iLogin_index]->nn << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> m_pUser_List[m_iLogin_index]->pn;
			cout << Last_pn << " -> " << m_pUser_List[m_iLogin_index]->pn << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}

void Login::Starting()
{
	int select;
	while (1)
	{
		system("cls");
		cout << "======ȯ �� �� �� ��======" << endl;
		cout << " 1. ȸ�� ����" << endl;
		cout << " 2. ȸ�� ���� ����" << endl;
		cout << " 3. ���ư���" << endl;
		cout << "�Է� >>>> ";
		cin >> select;
		system("cls");
		switch (select)
		{
		case 1:
			ShowUser();
			break;
		case 2:
			AlterUser();
			break;
		case 3:
			return;
		}
		system("pause");
	}
}

int Login::LoginUser()
{
	string input_id;
	string input_pw;
	while (1)
	{
		system("cls");
		cout << "���̵� �Է� : ";
		cin >> input_id;
		cout << "��й�ȣ �Է� : ";
		cin >> input_pw;
		if (m_iUser_Count == 0)
		{
			cout << "������ ȸ���� �����ϴ�." << endl;
			return FAIL;
		}
		for (int i = 0; i < m_iUser_Count; i++)
		{
			if (input_id == m_pUser_List[i]->id && input_pw == m_pUser_List[i]->pw)
			{
				m_iLogin_index = i;
				return SUCCESS;
			}
		}
		cout << "��ġ�ϴ� ���̵�� ��й�ȣ�� �����ϴ�." << endl;
		system("pause");
		continue;
	}
}

Login::~Login()
{
	for (int i = 0; i < MAX; i++)
	{
		if (m_pUser_List[i] != NULL)
			delete m_pUser_List[i];
	}
}