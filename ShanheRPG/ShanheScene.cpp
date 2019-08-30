#include "pch.h"
#include "ShanheScene.h"

#include "ShanheBuffer.h"
#include "ShanheMap.h"
#include "ShanhePlayer.h"


ShanheScene::ShanheScene(int width, int height)
{
	m_width = width;
	m_height = height;

	m_map = nullptr;
	m_player = nullptr;

	m_type = SHANHE::SceneType::Player_Center;

	m_buffer = new ShanheBuffer(m_width, m_height);

	if (m_width % 2 == 1)
		m_halfWidth = (m_width + 1) / 2;
	else
		m_halfWidth = m_width / 2 - 1;

	if (m_height % 2 == 1)
		m_halfHeight = (m_height + 1) / 2;
	else
		m_halfHeight = m_height / 2 - 1;
}

ShanheScene::~ShanheScene()
{
}

void ShanheScene::SetMap(ShanheMap * map)
{
	m_map = map;
}

void ShanheScene::SetPlayer(ShanhePlayer * player)
{
	m_player = player;
}

ShanheBuffer * ShanheScene::GetScene()
{
	// 先将缓冲区清为空
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			m_buffer->SetBuffer(x, y, L' ');

		}
	}
	
	// 确定需要显示的地图范围， beginX, beginY，endX, endY 表示将显示的地图矩形范围的左上、右下坐标
	SHANHE::MapSize ms = m_map->GetMapSize();
	SHANHE::Position playerPos = m_player->GetPosition();

	int beginX = playerPos.x - m_halfWidth;
	int beginY = playerPos.y - m_halfHeight;
	int endX = playerPos.x + m_halfWidth;
	int endY = playerPos.y + m_halfHeight;
	
	ShanheObject* obj = nullptr;

	// 若指定坐标不存在，则输出空格，否则输出地图元素
	for (int localY = 0, y = beginY; y < endY; y++, localY++)
	{
		for (int localX = 0, x = beginX; x < endX; x++, localX++)
		{
			obj = m_map->GetMapObject(x, y);
			if (obj == nullptr)
			{
				m_buffer->SetBuffer(localX, localY, L' ');
			}
			else
			{
				m_buffer->SetBuffer(localX, localY, obj->GetCharacter());
			}

		}
	}


	m_buffer->SetBuffer(m_halfWidth, m_halfHeight, m_player->GetCharacter());

	return m_buffer;
}
