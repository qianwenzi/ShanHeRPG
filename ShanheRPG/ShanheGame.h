#pragma once

// 头文件引用
#include <vector>

// 前置声明
class ShanheMap;
class ShanheBuffer;
class ShanhePlayer;
class ShanheDevice;
class ShanheInput;
class ShanheScene;


//山河RPG游戏类，控制游戏流程
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
