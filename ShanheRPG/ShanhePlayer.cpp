#include "pch.h"
#include "ShanhePlayer.h"


ShanhePlayer::ShanhePlayer()
{
	m_x = 5;
	m_y = 5;
	m_character = L'玩';
}


ShanhePlayer::~ShanhePlayer()
{
}

void ShanhePlayer::onCollision(ShanheObject * collision)
{
	// 响应碰撞消息，若碰撞物体类型为 WALL 则将玩家位置设置到(5, 5)
	if (collision->GetType() == SHANHE::ObjectType::WALL)
	{
		m_x = 5;
		m_y = 5;
	}
}

void ShanhePlayer::Walk(int x, int y)
{
	// 走路 x, y 为偏移量
	m_x += x;
	m_y += y;
}
