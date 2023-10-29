#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

enum Alignment
{
	Left, Right, Top, Bottom, TopLeft, TopRight, BottomLeft, BottomRight, Center
};

class Minimap
{
public:
	Minimap(sf::RenderWindow *p_rw, sf::Vector2f PosMin, sf::Vector2f PosMax, Alignment ali = TopLeft);
	~Minimap();

	void setViewport(sf::FloatRect rect) { pMiniMapView->setViewport(rect); }
	void setViewport(Alignment ali);
	void setAsCurrent() { rw->setView(*pMiniMapView); }
	void setMinMaxPos(sf::Vector2f Min, sf::Vector2f Max) { PosMin = Min; PosMax = Max; setCenter(); }
	void setMinMaxPos(float Min_x, float Min_y, float Max_x, float Max_y)
	{ PosMin = sf::Vector2f(Min_x, Min_y); PosMax = sf::Vector2f(Max_x, Max_y); setCenter(); }

private:
	void setCenter();

	sf::View *pMiniMapView;

	sf::RenderWindow *rw;

	sf::Vector2f PosMin, PosMax, offset;
	float scale;
};

