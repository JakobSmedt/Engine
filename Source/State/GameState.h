#pragma once

#include <functional>
#include <iostream>

#include "BaseState.h"
#include "../GUI/GUIManager.h"
#include "../Physics/PhysicScene.h"
#include "../GUI/DialogSystem/DialogSystem.h"
#include "../GUI/TileMap.h"
#include "../Camera/Camera.h"
#include "../Camera/Minimap.h"

class GameState : public BaseState
{
public:
	GameState(sf::RenderWindow *p_rw, StateManager *p_sm);
	~GameState();

	void handleEvent(sf::Event e)				override;
	void handleInput()							override;
	void update(float frametime)				override;
	void fixedUpdate(float frametime)			override;
	void render()								override;

	void setVolume(float f)						override;
private:
	Camera *pCamera;
	Minimap *pMiniMap;

	gui::GUIManager *GUI_Manager;

	TileMap *pMap;

	//DialogSystem *DS;
	//phy::PhysicScene *PHY_Scene;

	//sf::Sprite *pTest;

	//int level[128];
};

