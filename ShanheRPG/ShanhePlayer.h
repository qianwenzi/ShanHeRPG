#pragma once

// 头文件引用
#include "ShanheObject.h"

// 山河RPG玩家类
class ShanhePlayer :
	public ShanheObject
{
public:
	ShanhePlayer();
	~ShanhePlayer();

	virtual void onCollision(ShanheObject* collision);

public:
	void Walk(int x, int y);
};

