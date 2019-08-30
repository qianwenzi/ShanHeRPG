#pragma once

// 前置声明
class ShanheCollision;

// 头文件引用
#include "ShanheUtilities.h"

// 山河RPG地图元素，是地图的基本组成部件
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

