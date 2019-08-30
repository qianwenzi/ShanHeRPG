// ShanheRPG.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include "Shanhe.h"

int main()
{
	const int mapW = 100, mapH = 50;
	
	ShanheGame game;
	ShanheMap* map = new ShanheMap(mapW, mapH);
	map->CreateWall();
	game.AddMap(map);

	game.Init();
	game.Start();

}

