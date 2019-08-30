#pragma once

//ɽ��RPG�ĳ��ýṹ�塢ö�ٱ�������
namespace SHANHE
{
	enum KeyValue
	{
		KEY_W = 0x57,
		KEY_A = 0x41,
		KEY_S = 0x53,
		KEY_D = 0x44
	};

	struct bufferInfo
	{
		int width;
		int height;
		wchar_t** buffer;
	};

	enum ObjectType
	{
		WALL,
		PLAYER,
		AIR,
		ENEMY,
		TRIGGER,
		NPC
	};

	struct MapSize
	{
		int width;
		int height;
	};

	struct Position
	{
		int x, y;
	};

	enum SceneType
	{
		Player_Center
	};
}