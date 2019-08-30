#include "pch.h"
#include "ShanheDevice.h"
#include "ShanheBuffer.h"

#include <locale>

using namespace std;

ShanheDevice::ShanheDevice()
{
	// 获取控制台句柄，以便后面控制光标
	m_hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// 隐藏光标，避免闪烁
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
	// 将光标移动至(0, 0)处
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(m_hOut, pos);
}

void ShanheDevice::DrawBuffer(ShanheBuffer * buffer)
{
	// 设置中文输入
	locale loc("chs");
	wcout.imbue(loc);

	// 绘制缓冲区
	auto bf = buffer->GetBufferInfo();

	for (int y = 0; y < bf->height; y++)
	{
		for (int x = 0; x < bf->width; x++)
		{
			// 由于空格是中文字符的一半宽，故为了保持地图元素对齐，当缓冲区中的字符为空格时，输出两个空格
			if (bf->buffer[x][y] == L' ')
				wcout << L"  ";
			else
				wcout << bf->buffer[x][y];
		}
		cout << endl;
	}
	
}

