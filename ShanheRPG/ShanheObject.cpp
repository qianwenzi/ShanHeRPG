#include "pch.h"
#include "ShanheObject.h"

ShanheObject::ShanheObject()
{
	// ≥ı ºªØ
	m_x = 0; m_y = 0;
	m_type = SHANHE::ObjectType::AIR;
	m_isWalkable = true;
	m_character = L'ø’';
}


ShanheObject::~ShanheObject()
{
}

wchar_t ShanheObject::GetCharacter()
{
	return m_character;
}

void ShanheObject::SetCharacter(wchar_t character)
{
	m_character = character;
}

SHANHE::Position ShanheObject::GetPosition()
{
	SHANHE::Position pos;
	pos.x = m_x;
	pos.y = m_y;

	return pos;
}

bool ShanheObject::GetIsWalkable()
{
	return m_isWalkable;
}

void ShanheObject::SetIsWalkable(bool isWalkable)
{
	m_isWalkable = isWalkable;
}

SHANHE::ObjectType ShanheObject::GetType()
{
	return m_type;
}

void ShanheObject::SetType(SHANHE::ObjectType type)
{
	m_type = type;
}

void ShanheObject::onCollision(ShanheObject * collision)
{
}
