#include "gugu.h"

void gugu::GuguManager()
{
	while (1)
	{
		system("cls");
		cout << "���� ���� �����Ͻðڽ��ϱ�?" << endl;
		cout << " (Yes 1, No 2)" << endl;
		cin >> m_iselect;
		if (m_iselect == 1)
		{
			cout << "�ּ� �� �Է� : ";
			cin >> m_imin;
			cout << "�ִ� �� �Է� : ";
			cin >> m_imax;
			if (m_imin < 2 || m_imin > 9)
				cout << "���۴��� �������� ����ϴ�." << endl;
			else if (m_imax < 2 || m_imax > 9)
				cout << "������ �������� ����ϴ�." << endl;
			else if (m_imin >= m_imax)
				cout << "���۴��� ���ܺ��� ũ�ų� �����ϴ�." << endl;
			else
				Gugu(m_imin, m_imax);
		}
		else if (m_iselect == 2)
			Gugu();
		else
		{
			cout << "�߸� �Է�" << endl;
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
				cout << "======" << j << "��======" << "\t";
			else
				cout << "  " << j << " x " << i << " = " << i * j << "\t";
		}
		cout << endl;
	}
}
