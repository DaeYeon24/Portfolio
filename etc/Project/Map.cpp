#include "Map.h"

Map::Map()
{
	cout << "¸Ê X ÀÔ·Â : ";
	cin >> m_ix;
	cout << "¸Ê Y ÀÔ·Â : ";
	cin >> m_iy;
	cout << "¸Ê °¡·Î ±æÀÌ ÀÔ·Â : ";
	cin >> m_iWidth;
	cout << "¸Ê ¼¼·Î ±æÀÌ ÀÔ·Â : ";
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