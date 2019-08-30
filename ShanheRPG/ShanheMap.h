#pragma once

// ͷ�ļ�����
#include "ShanheUtilities.h"
#include <string>

// ǰ������
class ShanheObject;

// ɽ��RPG��ͼ��
class ShanheMap
{
public:
	ShanheMap(int width, int height);
	~ShanheMap();

public:
	void SetMapObject(int x, int y, ShanheObject obj);

	ShanheObject* GetMapObject(int x, int y);
	ShanheObject* GetMapObject(SHANHE::Position pos);
	ShanheObject** GetMapObjects();

	SHANHE::MapSize GetMapSize();

	void CreateWall();

private:
	std::string m_name;

	int m_width, m_height;
	ShanheObject** m_mapObjects;
};

