#pragma once
#include <iostream>
#include <string>
using namespace std;

#define GROUPNUM 1
#define GROUPNUMNEXT 2
//공용 010 SKT 011, 017 KT 016, 018 LG 019
//서울 02
//경기 031 //인천 032 //강원 033
//충남 041 //대전 042 //충북 043
//부산 051 //울산 052 //대구 053 //경북 054 //경남 055
//전남 061 //광주 062 //전북 063 //제주 064

enum TRUENUM // 두번째 자리수 판별
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

enum TELECOMNUM //통신사 세번째 번호 판별
{
	TELECOMNUM_PUBLIC = 48,
	TELECOMNUM_SKT1,
	TELECOMNUM_KT1 = 54,
	TELECOMNUM_SKT2,
	TELECOMNUM_KT2,
	TELECOMNUM_LG
};

enum REGIONNUM //지역 세번째 번호 판별
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
		cout << "완성된 번호 : " << m_chpNum << endl;
	}
};