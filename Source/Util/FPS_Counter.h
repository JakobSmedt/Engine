#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class FPS
{
public:
	FPS();
	~FPS();

	void update();
	void render(sf::RenderWindow *rw);
private:
	sf::Clock *pUpdateC;
	sf::Text  *pFPS;

	int framecount;
	float UpdateTime;
};

