#pragma once

// 前置声明
class ShanheBuffer;

// 提供绘图函数
class ShanheDevice
{
public:
	ShanheDevice();
	~ShanheDevice();

public:
	void clear();
	void DrawBuffer(ShanheBuffer* buffer);

private:
	HANDLE m_hOut;
};

