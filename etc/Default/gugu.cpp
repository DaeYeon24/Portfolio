#include "gugu.h"

void gugu::GuguManager()
{
	while (1)
	{
		system("cls");
		cout << "최종 값을 변경하시겠습니까?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "최소 값 입력 : ";
			cin >> m_imin;
			cout << "최대 값 입력 : ";
			cin >> m_imax;
			if (m_imin < 2 || m_imin > 9)
				cout << "시작단이 범위에서 벗어납니다." << endl;
			else if (m_imax < 2 || m_imax > 9)
				cout << "끝단이 범위에서 벗어납니다." << endl;
			else if (m_imin >= m_imax)
				cout << "시작단이 끝단보다 크거나 같습니다." << endl;
			else
				Gugu(m_imin, m_imax);
		}
		else if (m_iselect == 2)
			Gugu();
		else
		{
			cout << "잘못 입력" << endl;
			system("pause");
			continue;
		}
		return;
	}
}

void gugu::Gugu(int imin, int imax)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = imin; j <= imax; j++)
		{
			if (i == 0)
				cout << "======" << j << "단======" << "\t";
			else
				cout << "  " << j << " x " << i << " = " << i * j << "\t";
		}
		cout << endl;
	}
}
