#pragma once

// 头文件引用
#include "ShanheUtilities.h"

// 绘图缓冲区，是唯一内被直接绘制的东西
class ShanheBuffer
{
public:
	ShanheBuffer(int width, int height);
	~ShanheBuffer();

public:
	SHANHE::bufferInfo* GetBufferInfo();
	void SetBuffer(int x, int y, wchar_t value);
private:
	wchar_t** m_printBuffer;

	int m_width;
	int m_height;


};

