#pragma once

// ǰ������
class ShanheBuffer;

// �ṩ��ͼ����
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

