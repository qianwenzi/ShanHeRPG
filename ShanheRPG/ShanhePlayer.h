#pragma once

// ͷ�ļ�����
#include "ShanheObject.h"

// ɽ��RPG�����
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

