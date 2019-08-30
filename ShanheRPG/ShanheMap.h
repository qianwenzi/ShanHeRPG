#pragma once

// 头文件引用
#include "ShanheUtilities.h"
#include <string>

// 前置声明
class ShanheObject;

// 山河RPG地图类
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

