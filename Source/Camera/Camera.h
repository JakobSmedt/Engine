#pragma once

//#include <iostream>

#include <SFML/Graphics.hpp>

class Camera
{
public:
	 Camera(sf::RenderWindow *p_rw, sf::Vector2f scalemin = sf::Vector2f(0.25f, 0.25f), sf::Vector2f scalemax = sf::Vector2f(2.f, 2.f));
	~Camera();

	void handelKeys(sf::Event e);
	void handleInput();
	void update(float frametime);
	void fixedUpdate(float frametime);

	void setCenter(sf::Vector2f center) { pView->setCenter(center); }
	void setCenter(float x, float y) { pView->setCenter(sf::Vector2f(x, y)); }
	void setAsCurrent() { rw->setView(*pView); }
	void setZoom(float zoom);
	void setMinMaxPos(sf::Vector2f Min, sf::Vector2f Max) { PosMin = Min; PosMax = Max; }
	void setMinMaxPos(float Min_x, float Min_y, float Max_x, float Max_y)
			{ PosMin = sf::Vector2f(Min_x, Min_y); PosMax = sf::Vector2f(Max_x, Max_y); }
private:
	void updatescale();

	sf::View *pView;

	sf::Vector2f Scale, ScaleMin, ScaleMax, PosMin, PosMax;
	sf::RenderWindow *rw;
};

