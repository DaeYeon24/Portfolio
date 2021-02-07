#include "TelephoneNumber.h"

TelephoneNumber::TelephoneNumber()
{
	cout << "번호 입력 : ";
	cin >> m_strTemp;
	m_chpNum = new char[m_strTemp.length() + 3];
	strcpy(m_chpNum, m_strTemp.c_str());
}

void TelephoneNumber::NewSetting()
{
	cout << "정상적인 번호가 아닙니다." << endl;
	delete[] m_chpNum;
	system("pause");
	cout << "번호 입력 : ";
	cin >> m_strTemp;
	m_chpNum = new char[m_strTemp.length() + 3];
	strcpy(m_chpNum, m_strTemp.c_str());
}

void TelephoneNumber::Matching()
{
	while (1)
	 {
		if (m_chpNum[GROUPNUM] == PHONE && strlen(m_chpNum) == 11)
		{
			switch (m_chpNum[GROUPNUMNEXT])
			{
			case TELECOMNUM_PUBLIC:
			case TELECOMNUM_SKT1:
			case TELECOMNUM_KT1:
			case TELECOMNUM_SKT2:
			case TELECOMNUM_KT2:
			case TELECOMNUM_LG:
				MakingNumber();
				system("pause");
				break;
			default:
				NewSetting();
				continue;
			}
		}
		else if (m_chpNum[GROUPNUM] == SEOUL && strlen(m_chpNum) == 9)
		{
			MakingNumber();
			system("pause");
		}
		else if (m_chpNum[GROUPNUM] >= REGIONSTART && m_chpNum[GROUPNUM] <= REGIONEND && strlen(m_chpNum) == 10)
		{
			if (RegionMatching() == false)
				continue;
			else
				system("pause");
		}
		else
		{
			NewSetting();
			continue;
		}
		return;
	 }
}

bool TelephoneNumber::RegionMatching()
{
	if (m_chpNum[GROUPNUM] == GYEONGGI || m_chpNum[GROUPNUM] == CHUNGCHEONG)
	{
		switch (m_chpNum[GROUPNUMNEXT])
		{
		case REGIONNUM_NUM1:
		case REGIONNUM_NUM2:
		case REGIONNUM_NUM3:
			MakingNumber();
			return true;
		default:
			NewSetting();
			return false;
		}
	}
	else if (m_chpNum[GROUPNUM] == GYEONGSANG)
	{
		switch (m_chpNum[GROUPNUMNEXT])
		{
		case REGIONNUM_NUM1:
		case REGIONNUM_NUM2:
		case REGIONNUM_NUM3:
		case REGIONNUM_NUM4:
		case REGIONNUM_NUM5:
			MakingNumber();
			return true;
		default:
			NewSetting();
			return false;
		}
	}
	else if (m_chpNum[GROUPNUM] == JEOLLA)
	{
		switch (m_chpNum[GROUPNUMNEXT])
		{
		case REGIONNUM_NUM1:
		case REGIONNUM_NUM2:
		case REGIONNUM_NUM3:
		case REGIONNUM_NUM4:
			MakingNumber();
			return true;
		default:
			NewSetting();
			return false;
		}
	}
}

void TelephoneNumber::MakingNumber()
{
	int Start = strlen(m_chpNum) + 1;
	int Hyphen1, Hyphen2;
	if (strlen(m_chpNum) < 11)
	{
		Hyphen1 = 5;
		Hyphen2 = 9;
	}
	else
	{
		Hyphen1 = 5;
		Hyphen2 = 10;
	}
	int Count = 0;
	int Point = 2;
	m_chpNum[Start + 1] = NULL;
	for (int i = Start; ;i--)
	{
		Count++;
		if (Count == Hyphen1 || Count == Hyphen2)
		{
			m_chpNum[i] = '-';
			Point--;
		}			
		else
		{
			m_chpNum[i] = m_chpNum[i - Point];
		}
		if (i - Point == 0)
			break;
	}
	Show();
}

TelephoneNumber::~TelephoneNumber()
{
	delete[] m_chpNum;
}