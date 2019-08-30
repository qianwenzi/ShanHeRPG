#pragma once

// ǰ������
class ShanheCollision;

// ͷ�ļ�����
#include "ShanheUtilities.h"

// ɽ��RPG��ͼԪ�أ��ǵ�ͼ�Ļ�����ɲ���
class ShanheObject
{
public:
	ShanheObject();
	~ShanheObject();

	wchar_t GetCharacter();
	void SetCharacter(wchar_t character);
	SHANHE::Position GetPosition();

	bool GetIsWalkable();
	void SetIsWalkable(bool isWalkable);

	SHANHE::ObjectType GetType();
	void SetType(SHANHE::ObjectType type);

	virtual void onCollision(ShanheObject* collision);
protected:
	int m_x, m_y;
	wchar_t m_character;
	bool m_isWalkable;
	SHANHE::ObjectType m_type;
};

