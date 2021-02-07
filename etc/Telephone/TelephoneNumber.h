#pragma once
#include <iostream>
#include <string>
using namespace std;

#define GROUPNUM 1
#define GROUPNUMNEXT 2
//���� 010 SKT 011, 017 KT 016, 018 LG 019
//���� 02
//��� 031 //��õ 032 //���� 033
//�泲 041 //���� 042 //��� 043
//�λ� 051 //��� 052 //�뱸 053 //��� 054 //�泲 055
//���� 061 //���� 062 //���� 063 //���� 064

enum TRUENUM // �ι�° �ڸ��� �Ǻ�
{
	PHONE = 49,
	SEOUL,
	REGIONSTART = 51,
	GYEONGGI = 51,
	CHUNGCHEONG,
	GYEONGSANG,
	JEOLLA = 54,
	REGIONEND = 54
};

enum TELECOMNUM //��Ż� ����° ��ȣ �Ǻ�
{
	TELECOMNUM_PUBLIC = 48,
	TELECOMNUM_SKT1,
	TELECOMNUM_KT1 = 54,
	TELECOMNUM_SKT2,
	TELECOMNUM_KT2,
	TELECOMNUM_LG
};

enum REGIONNUM //���� ����° ��ȣ �Ǻ�
{
	REGIONNUM_NUM1 = 49,
	REGIONNUM_NUM2,
	REGIONNUM_NUM3,
	REGIONNUM_NUM4,
	REGIONNUM_NUM5
};

class TelephoneNumber
{
private:
	char* m_chpNum;
	string m_strTemp;
public:
	TelephoneNumber();
	~TelephoneNumber();
	void NewSetting();
	void Matching();
	bool RegionMatching();
	void MakingNumber();
	inline void Show()
	{
		cout << "�ϼ��� ��ȣ : " << m_chpNum << endl;
	}
};