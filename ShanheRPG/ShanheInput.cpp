#include "pch.h"
#include "ShanheInput.h"



ShanheInput::ShanheInput()
{
}


ShanheInput::~ShanheInput()
{
}

void ShanheInput::Update()
{
}

bool ShanheInput::KeyDown(int key)
{
	// 判断按键是否处于按下状态
	if (GetAsyncKeyState(key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
