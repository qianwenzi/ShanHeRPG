#pragma once

// 头文件引用
#include "ShanheUtilities.h"

// 前置声明
class ShanheBuffer;
class ShanheMap;
class ShanhePlayer;

// 山河RPG场景类，负责沈城游戏画面的每一帧

class ShanheScene
{
public:
	ShanheScene(int width, int height);
	~ShanheScene();

public:
	void SetMap(ShanheMap* map);
	void SetPlayer(ShanhePlayer* player);
	
	ShanheBuffer* GetScene();

private:
	int m_width, m_height;
	int m_halfWidth, m_halfHeight;

	SHANHE::SceneType m_type;

	ShanheMap* m_map;
	ShanhePlayer* m_player;

	ShanheBuffer* m_buffer;
};

