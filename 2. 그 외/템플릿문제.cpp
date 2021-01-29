#include <iostream>
using namespace std;

template <typename T>
T func1(T value)
{
	return ++value;
}

//template <typename T1, typename T2, typename T3>
//void func4(T1 a, T2 b, T3 c)
//{
//	cout << "두 값 입력 : ";
//	cin >> a >> b;
//	cout << func2(a, b) << endl;
//	cout << "세 값 입력 : ";
//	cin >> a >> b >> c;
//	cout << func3(a, b, c) << endl;
//}

template <typename T>
T func2(T value1, T value2)
{
	if (value1 >= value2)
		return value2;
	else
		return value1;
}

template <typename T>
T func3(T value1, T value2, T value3)
{
	if (value1 >= value2 && value1 >= value3)
		return value1;
	else if (value2 >= value1 && value2 >= value3)
		return value2;
	else
		return value3;
}

void main()
{
	int _int1 = 1, _int2, _int3;
	float _float1 = 1.1f, _float2, _float3;
	double _double1 = 2.22, _double2, _double3;
	char _char1 = 'a', _char2, _char3;
	cout << func1(_int1) << endl;
	cout << func1(_float1) << endl;
	cout << func1(_double1) << endl;
	cout << func1(_char1) << endl;
	int select;
	cout << "자료형 선택 <1. int 2. float 3. double 4. char> : ";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "두 값 입력 : ";
		cin >> _int1 >> _int2;
		cout << func2(_int1, _int2) << endl;
		cout << "세 값 입력 : ";
		cin >> _int1 >> _int2 >> _int3;
		cout << func3(_int1, _int2, _int3) << endl;
		break;
	case 2:
		cout << "두 값 입력 : ";
		cin >> _float1 >> _float2;
		cout << func2(_float1, _float2) << endl;
		cout << "세 값 입력 : ";
		cin >> _float1 >> _float2 >> _float3;
		cout << func3(_float1, _float2, _float3) << endl;
		break;
	case 3:
		cout << "두 값 입력 : ";
		cin >> _double1 >> _double2;
		cout << func2(_double1, _double2) << endl;
		cout << "세 값 입력 : ";
		cin >> _double1 >> _double2 >> _double3;
		cout << func3(_double1, _double2, _double3) << endl;
		break;
	case 4:
		cout << "두 값 입력 : ";
		cin >> _char1 >> _char2;
		cout << func2(_char1, _char2) << endl;
		cout << "세 값 입력 : ";
		cin >> _char1 >> _char2 >> _char3;
		cout << func3(_char1, _char2, _char3) << endl;
		break;
	}
}