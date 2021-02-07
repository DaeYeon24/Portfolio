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
		cout << "====Login====(회원 수[" << m_iUser_Count << "명])" << endl;
		cout << "  1. 회원가입" << endl;
		cout << "  2. 로그인" << endl;
		cout << "  3. 종료" << endl;
		cout << "입력 : ";
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
			cout << "아이디 입력(3글자 이상, 한글 X) : ";
		}
		else if (IDorPW == PW)
			cout << "패스워드 입력(8글자 이상, 한글 X, 숫자 필수) : ";
		cin >> input;
		input_length = input.length();
		if (IDorPW == ID && input.length() < 3 || IDorPW == PW && input.length() < 8)
		{
			LetterCount = false;
			cout << "입력 수가 적습니다." << endl;
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
			cout << "숫자를 포함해야합니다." << endl;
		if (Letter == false)
			cout << "영문으로 작성하세요." << endl;
		if (Letter == false || LetterCount == false || essential == false)
		{
			system("pause");
			continue;
		}
		if (IDorPW == PW)
		{
			cout << "패스워드 확인 : ";
			cin >> pw_check;
			if (pw_check != input)
			{
				cout << "확인한 패스워드가 일치하지 않습니다." << endl;
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
	cout << "닉네임 입력 : ";
	cin >> m_pUser_List[m_iUser_Count]->nn;
	cout << "나이 입력 : ";
	cin >> m_pUser_List[m_iUser_Count]->age;
	cout << "휴대폰 번호 입력 : ";
	cin >> m_pUser_List[m_iUser_Count]->pn;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
	m_pUser_List[m_iUser_Count]->mileage = 1000;
	return;
}

void Login::ShowUser()
{
	cout << "==============회원 정보==============" << endl;
	cout << "ID : " << m_pUser_List[m_iLogin_index]->id << "\t닉네임 : " << m_pUser_List[m_iLogin_index]->nn << endl;
	cout << "나이 : " << m_pUser_List[m_iLogin_index]->age << "\t휴대폰 번호 : " << m_pUser_List[m_iLogin_index]->pn << endl;
	cout << "마일리지 : " << m_pUser_List[m_iLogin_index]->mileage << endl;
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
		cout << "  1. 닉네임 변경" << endl;
		cout << "  2. 나이 변경" << endl;
		cout << "  3. 휴대폰 번호 변경" << endl;
		cout << "  4. 돌아가기" << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			Last_nn = m_pUser_List[m_iLogin_index]->nn;
			cout << "현재 닉네임 : " << m_pUser_List[m_iLogin_index]->nn << endl;
			cout << "변경할 닉네임 입력 : ";
			cin >> m_pUser_List[m_iLogin_index]->nn;
			cout << Last_nn << " -> " << m_pUser_List[m_iLogin_index]->nn << endl;
			break;
		case 2:
			Last_age = m_pUser_List[m_iLogin_index]->age;
			cout << "현재 나이 : " << m_pUser_List[m_iLogin_index]->age << endl;
			cout << "변경할 나이 입력 : ";
			cin >> m_pUser_List[m_iLogin_index]->age;
			cout << Last_age << " -> " << m_pUser_List[m_iLogin_index]->age << endl;
			break;
		case 3:
			Last_pn = m_pUser_List[m_iLogin_index]->pn;
			cout << "현재 휴대폰 번호 : " << m_pUser_List[m_iLogin_index]->nn << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
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
		cout << "======환 영 합 니 다======" << endl;
		cout << " 1. 회원 정보" << endl;
		cout << " 2. 회원 정보 변경" << endl;
		cout << " 3. 돌아가기" << endl;
		cout << "입력 >>>> ";
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
		cout << "아이디 입력 : ";
		cin >> input_id;
		cout << "비밀번호 입력 : ";
		cin >> input_pw;
		if (m_iUser_Count == 0)
		{
			cout << "생성된 회원이 없습니다." << endl;
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
		cout << "일치하는 아이디와 비밀번호가 없습니다." << endl;
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