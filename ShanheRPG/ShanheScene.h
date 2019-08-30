#pragma once

// ͷ�ļ�����
#include "ShanheUtilities.h"

// ǰ������
class ShanheBuffer;
class ShanheMap;
class ShanhePlayer;

// ɽ��RPG�����࣬���������Ϸ�����ÿһ֡

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

