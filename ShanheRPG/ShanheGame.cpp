#include "pch.h"
#include "ShanheGame.h"

#include "ShanheMap.h"
#include "ShanheBuffer.h"
#include "ShanhePlayer.h"
#include "ShanheDevice.h"
#include "ShanheInput.h"
#include "ShanheScene.h"

ShanheGame::ShanheGame()
{
	m_device = new ShanheDevice;
	m_input = new ShanheInput;
	m_buffer = nullptr;
	m_mainMapIndex = 0;
	m_currentMapIndex = 0;
}


ShanheGame::~ShanheGame()
{
}

void ShanheGame::Init()
{
	ShanheMap* map = m_mapList[m_mainMapIndex];
	SHANHE::MapSize ms = map->GetMapSize();

	m_player = new ShanhePlayer;
	
	m_scene = new ShanheScene(59, 29);
	m_scene->SetMap(m_mapList[m_mainMapIndex]);
	m_scene->SetPlayer(m_player);
}

void ShanheGame::Start()
{
	while (true)
	{
		Update(m_input);
		Draw(m_device);
	}
}

void ShanheGame::Update(ShanheInput * input)
{
	ShanheObject* obj;
	SHANHE::Position playerPos;
	playerPos = m_player->GetPosition();

	if (input->KeyDown(SHANHE::KeyValue::KEY_D))
	{
		obj = m_mapList[m_currentMapIndex]->GetMapObject(playerPos.x + 1, playerPos.y);
		if (obj->GetIsWalkable() == true)
		{
			m_player->onCollision(obj);
			m_player->Walk(1, 0);
		}
		else
		{
			m_player->onCollision(obj);
		}
		
	}


	if (input->KeyDown(SHANHE::KeyValue::KEY_S))
	{
		obj = m_mapList[m_currentMapIndex]->GetMapObject(playerPos.x, playerPos.y + 1);
		if (obj->GetIsWalkable() == true)
		{
			m_player->onCollision(obj);
			m_player->Walk(0, 1);
		}
		else
		{
			m_player->onCollision(obj);
		}
	}


	if (input->KeyDown(SHANHE::KeyValue::KEY_A))
	{
		obj = m_mapList[m_currentMapIndex]->GetMapObject(playerPos.x - 1, playerPos.y);
		if (obj->GetIsWalkable() == true)
		{
			m_player->onCollision(obj);
			m_player->Walk(-1, 0);
		}
		else
		{
			m_player->onCollision(obj);
		}
	}


	if (input->KeyDown(SHANHE::KeyValue::KEY_W))
	{
		obj = m_mapList[m_currentMapIndex]->GetMapObject(playerPos.x, playerPos.y - 1);
		if (obj->GetIsWalkable() == true)
		{
			m_player->onCollision(obj);
			m_player->Walk(0, -1);
		}
		else
		{
			m_player->onCollision(obj);
		}
	}
}


void ShanheGame::Draw(ShanheDevice* device)
{
	device->clear();

	device->DrawBuffer(m_scene->GetScene());
}

void ShanheGame::AddMap(ShanheMap * map)
{
	m_mapList.push_back(map);
}

