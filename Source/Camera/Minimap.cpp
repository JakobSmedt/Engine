#include "Minimap.h"


Minimap::Minimap(sf::RenderWindow *p_rw, sf::Vector2f posmin, sf::Vector2f posmax, Alignment ali)
	: rw		(p_rw)
	, PosMin	(posmin)
	, PosMax	(posmax)
{
	pMiniMapView = new sf::View;

	scale = 0.5f;
	offset = sf::Vector2f(10.f, 10.f);
	
	setViewport(ali);

	setCenter();
}

Minimap::~Minimap()
{
	delete pMiniMapView;

	pMiniMapView = nullptr;
}

void Minimap::setViewport(Alignment pos)
{
	float w = PosMax.x - PosMin.x;
	float h = PosMax.y - PosMin.y;
	float min = std::min(w, h);

	float RWX = rw->getSize().x;
	float RWY = rw->getSize().y;

	switch (pos)
	{
	case Left:
		break;
	case Right:
		break;
	case Top:
		break;
	case Bottom:
		break;
	case TopLeft:
		pMiniMapView->setViewport(sf::FloatRect(offset.x / RWX, offset.y / RWY, scale * w / RWX, scale * h / RWY));
		break;
	case TopRight:
		break;
	case BottomLeft:
		break;
	case BottomRight:
		break;
	case Center:
		break;
	default:
		break;
	}
}

void Minimap::setCenter()
{
	pMiniMapView->zoom((PosMax.y - PosMin.y) / pMiniMapView->getSize().y);
	pMiniMapView->setCenter(PosMin.x + .5f*PosMax.x, PosMin.y + .5f*PosMax.y);
}
