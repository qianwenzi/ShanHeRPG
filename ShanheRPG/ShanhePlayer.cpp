#include "pch.h"
#include "ShanhePlayer.h"


ShanhePlayer::ShanhePlayer()
{
	m_x = 5;
	m_y = 5;
	m_character = L'��';
}


ShanhePlayer::~ShanhePlayer()
{
}

void ShanhePlayer::onCollision(ShanheObject * collision)
{
	// ��Ӧ��ײ��Ϣ������ײ��������Ϊ WALL �����λ�����õ�(5, 5)
	if (collision->GetType() == SHANHE::ObjectType::WALL)
	{
		m_x = 5;
		m_y = 5;
	}
}

void ShanhePlayer::Walk(int x, int y)
{
	// ��· x, y Ϊƫ����
	m_x += x;
	m_y += y;
}
