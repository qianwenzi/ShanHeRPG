#include "pch.h"
#include "ShanheBuffer.h"


ShanheBuffer::ShanheBuffer(int width, int height)
{
	m_height = height;
	m_width = width;

	// �����ڴ�
	m_printBuffer = new wchar_t*[width];
	for (int i = 0; i < width; i++)
	{
		m_printBuffer[i] = new wchar_t[height];
	}

	// ����ʾ�ַ���ʼ��Ϊ ��
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			m_printBuffer[x][y] = L'��';

		}
	}
}

ShanheBuffer::~ShanheBuffer()
{
	// �ͷ��ڴ�
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
	// ��֤ x, y �ڻ��������Ƿ���ڣ�������
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		m_printBuffer[x][y] = value;
	}
}
