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
	cout << "닉네임 입력 : ";
	cin >> user->nn;
	cout << "나이 입력 : ";
	cin >> user->age;
	cout << "휴대폰 번호 입력 : ";
	cin >> user->pn;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
	user->mileage = 1000;
	return;
}
void ShowUser(User* user)
{
	cout << "==============회원 정보==============" << endl;
	cout << "ID : " << user->id << "\t닉네임 : " << user->nn << endl;
	cout << "나이 : " << user->age << "\t휴대폰 번호 : " << user->pn << endl;
	cout << "마일리지 : " << user->mileage << endl;
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
		cout << "  1. 닉네임 변경" << endl;
		cout << "  2. 나이 변경" << endl;
		cout << "  3. 휴대폰 번호 변경" << endl;
		cout << "  4. 돌아가기" << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			Last_nn = user->nn;
			cout << "현재 닉네임 : " << user->nn << endl;
			cout << "변경할 닉네임 입력 : ";
			cin >> user->nn;
			cout << Last_nn << " -> " << user->nn << endl;
			break;
		case 2:
			Last_age = user->age;
			cout << "현재 나이 : " << user->age << endl;
			cout << "변경할 나이 입력 : ";
			cin >> user->age;
			cout << Last_age << " -> " << user->age << endl;
			break;
		case 3:
			Last_pn = user->pn;
			cout << "현재 휴대폰 번호 : " << user->nn << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
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
		cout << "  1. 회원 정보" << endl;
		cout << "  2. 회원 정보 변경" << endl;
		cout << "  3. 로그아웃" << endl;
		cout << "입력 : ";
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
		cout << "아이디 입력 : ";
		cin >> input_id;
		cout << "비밀번호 입력 : ";
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
		cout << "일치하는 아이디와 비밀번호가 없습니다." << endl;
		system("pause");
		continue;
	}
}

void main()
{
	User User_List[MAX]; // 10명
	int Count = 0;
	int Select;
	while (1)
	{
		system("cls");
		cout << "====Login====(회원 수[" << Count << "명])" << endl;
		cout << "  1. 회원가입" << endl;
		cout << "  2. 로그인" << endl;
		cout << "  3. 종료" << endl;
		cout << "입력 : ";
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