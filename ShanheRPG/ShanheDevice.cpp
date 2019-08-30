#include "pch.h"
#include "ShanheDevice.h"
#include "ShanheBuffer.h"

#include <locale>

using namespace std;

ShanheDevice::ShanheDevice()
{
	// ��ȡ����̨������Ա������ƹ��
	m_hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���ع�꣬������˸
	::CONSOLE_CURSOR_INFO A;
	A.bVisible = FALSE;
	A.dwSize = 1;
	::SetConsoleCursorInfo(m_hOut, &A);
}


ShanheDevice::~ShanheDevice()
{
}

void ShanheDevice::clear()
{
	// ������ƶ���(0, 0)��
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(m_hOut, pos);
}

void ShanheDevice::DrawBuffer(ShanheBuffer * buffer)
{
	// ������������
	locale loc("chs");
	wcout.imbue(loc);

	// ���ƻ�����
	auto bf = buffer->GetBufferInfo();

	for (int y = 0; y < bf->height; y++)
	{
		for (int x = 0; x < bf->width; x++)
		{
			// ���ڿո��������ַ���һ�����Ϊ�˱��ֵ�ͼԪ�ض��룬���������е��ַ�Ϊ�ո�ʱ����������ո�
			if (bf->buffer[x][y] == L' ')
				wcout << L"  ";
			else
				wcout << bf->buffer[x][y];
		}
		cout << endl;
	}
	
}

