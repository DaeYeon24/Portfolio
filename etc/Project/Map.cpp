#include "Map.h"

Map::Map()
{
	cout << "�� X �Է� : ";
	cin >> m_ix;
	cout << "�� Y �Է� : ";
	cin >> m_iy;
	cout << "�� ���� ���� �Է� : ";
	cin >> m_iWidth;
	cout << "�� ���� ���� �Է� : ";
	cin >> m_iHeight;
	m_CharManager.CharSetting(m_ix, m_iy, m_iWidth, m_iHeight);
}

void Map::MapDraw()
{
	m_MapDrawManager.BoxDraw(m_ix, m_iy, m_iWidth, m_iHeight);
}

void Map::CharacterStart()
{
	m_CharManager.Start();
	m_CharManager.CharMove();
}

Map::~Map()
{

}