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
	// �жϰ����Ƿ��ڰ���״̬
	if (GetAsyncKeyState(key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
