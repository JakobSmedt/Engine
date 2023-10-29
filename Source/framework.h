#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Util/FPS_Counter.h"
#include "State/StateManager.h"

class framework
{
public:
	framework();
	~framework();

	void run();
	void quit();
private:
	void update(float frametime);
	void fixedUpdate(float frametime);
	void handel();
	void render();

	float calcframetime();

	sf::RenderWindow *pRenderWindow;
	sf::Event        *pMainEvent;
	
	StateManager     *pStatemanager;

	FPS *pFPS;

	sf::Clock *pframetimeclock;
	sf::Clock *pfixedframetimeclock;

	float timePerUpdate, lag;

	unsigned TPS;
	bool mIsRunning;
};