#include "pch.h"
#include "ShanheBuffer.h"


ShanheBuffer::ShanheBuffer(int width, int height)
{
	m_height = height;
	m_width = width;

	// 分配内存
	m_printBuffer = new wchar_t*[width];
	for (int i = 0; i < width; i++)
	{
		m_printBuffer[i] = new wchar_t[height];
	}

	// 将显示字符初始化为 空
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			m_printBuffer[x][y] = L'空';

		}
	}
}

ShanheBuffer::~ShanheBuffer()
{
	// 释放内存
	for (int i = 0; i < m_width; i++)
	{
		delete m_printBuffer[i];
	}

	delete m_printBuffer;
}

SHANHE::bufferInfo * ShanheBuffer::GetBufferInfo()
{
	SHANHE::bufferInfo * bf = new SHANHE::bufferInfo;
	bf->width = m_width;
	bf->height = m_height;
	bf->buffer = m_printBuffer;

	return bf;
}

void ShanheBuffer::SetBuffer(int x, int y, wchar_t value)
{
	// 验证 x, y 在缓冲区内是否存在，并返回
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		m_printBuffer[x][y] = value;
	}
}
