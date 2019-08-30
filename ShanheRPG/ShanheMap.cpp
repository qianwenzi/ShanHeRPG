#include "pch.h"
#include "ShanheMap.h"

#include "ShanheObject.h"


ShanheMap::ShanheMap(int width, int height)
{
	m_height = height;
	m_width = width;

	// �����ڴ�
	m_mapObjects = new ShanheObject*[width];
	for (int i = 0; i < width; i++)
	{
		m_mapObjects[i] = new ShanheObject[height];
	}

}

ShanheMap::~ShanheMap()
{
	// �ͷ��ڴ�
	for (int i = 0; i < m_width; i++)
		delete m_mapObjects[i];

	delete m_mapObjects;
}

ShanheObject* ShanheMap::GetMapObject(int x, int y)
{
	// �������Ԫ���Ƿ��ںϷ���������
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
		return &m_mapObjects[x][y];
	else
		return nullptr;
	
}

ShanheObject* ShanheMap::GetMapObject(SHANHE::Position pos)
{
	// �������Ԫ���Ƿ��ںϷ���������
	if (pos.x >= 0 && pos.x < m_width && pos.y >= 0 && pos.y < m_height)
	{
		return &m_mapObjects[pos.x][pos.y];
	}
	else
	{
		return nullptr;
	}
}

void ShanheMap::SetMapObject(int x, int y, ShanheObject obj)
{
	m_mapObjects[x][y] = obj;
}

ShanheObject ** ShanheMap::GetMapObjects()
{
	return m_mapObjects;
}

SHANHE::MapSize ShanheMap::GetMapSize()
{
	SHANHE::MapSize mapSize;
	mapSize.width = m_width;
	mapSize.height = m_height;

	return mapSize;
}

void ShanheMap::CreateWall()
{
	// �Ƚ������������ó� ǽ
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_mapObjects[x][y].SetCharacter(L'ǽ');
			m_mapObjects[x][y].SetIsWalkable(false);
			m_mapObjects[x][y].SetType(SHANHE::WALL);
		}
	}

	// �ٽ��м������Ϳճ� ����
	for (int y = 1; y < m_height - 1; y++)
	{
		for (int x = 1; x < m_width - 1; x++)
		{
			m_mapObjects[x][y].SetCharacter(L' ');
			m_mapObjects[x][y].SetIsWalkable(true);
			m_mapObjects[x][y].SetType(SHANHE::AIR);
		}
	}
}
