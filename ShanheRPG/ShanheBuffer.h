#pragma once

// ͷ�ļ�����
#include "ShanheUtilities.h"

// ��ͼ����������Ψһ�ڱ�ֱ�ӻ��ƵĶ���
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

