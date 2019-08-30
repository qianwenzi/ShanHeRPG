#pragma once

// ͷ�ļ�����
#include <vector>

// ǰ������
class ShanheMap;
class ShanheBuffer;
class ShanhePlayer;
class ShanheDevice;
class ShanheInput;
class ShanheScene;


//ɽ��RPG��Ϸ�࣬������Ϸ����
class ShanheGame
{
public:
	ShanheGame();
	~ShanheGame();

public:
	void Init();
	void Start();
	virtual void Update(ShanheInput* input);
	virtual void Draw(ShanheDevice* device);

	void AddMap(ShanheMap* map);

public:
	ShanheBuffer* m_buffer;
	ShanhePlayer* m_player;
	std::vector<ShanheMap*> m_mapList;
	int m_mainMapIndex, m_currentMapIndex;

	ShanheDevice* m_device;
	ShanheInput* m_input;
	ShanheScene* m_scene;
};
