#include "Camera.h"


Camera::Camera(sf::RenderWindow *p_rw, sf::Vector2f scalemin, sf::Vector2f scalemax)
	: rw		(p_rw)
	, ScaleMin	(scalemin)
	, ScaleMax	(scalemax)
{
	pView = new sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(float(rw->getSize().x), float(rw->getSize().y)));
	updatescale();

	PosMin = sf::Vector2f(-100.f, -100.f);
	PosMax = sf::Vector2f(100.f, 100.f);
}

Camera::~Camera()
{
	delete pView;

	pView = nullptr;
}

void Camera::handelKeys(sf::Event e)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		pView->move(sf::Vector2f(Scale.x * 0.f, Scale.y * -10.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pView->move(sf::Vector2f(Scale.x * -10.f, Scale.y * 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		pView->move(sf::Vector2f(Scale.x * 0.f, Scale.y * 10.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pView->move(sf::Vector2f(Scale.x * 10.f, Scale.y * 0.f));


	if ((pView->getCenter().y - 0.5f * pView->getSize().y) < PosMin.y)
		pView->setCenter(pView->getCenter().x, PosMin.y + 0.5f * pView->getSize().y);
	if ((pView->getCenter().x - 0.5f * pView->getSize().x) < PosMin.x)
		pView->setCenter(PosMin.x + 0.5f * pView->getSize().x, pView->getCenter().y);
	if ((pView->getCenter().y + 0.5f * pView->getSize().y) > PosMax.y)
		pView->setCenter(pView->getCenter().x, PosMax.y - 0.5f * pView->getSize().y);
	if ((pView->getCenter().x + 0.5f * pView->getSize().x) > PosMax.x)
		pView->setCenter(PosMax.x - 0.5f * pView->getSize().x, pView->getCenter().y);

	if (e.type == sf::Event::MouseWheelScrolled)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			setZoom(1.0f + 0.05f * e.mouseWheelScroll.delta);
		else
			setZoom(1.0f + 0.01f * e.mouseWheelScroll.delta);
	}
}

void Camera::handleInput()
{

}

void Camera::update(float frametime)
{

}

void Camera::fixedUpdate(float frametime)
{

}

void Camera::setZoom(float zoom)
{
	//if (zoom * Scale.x >= ScaleMin.x && zoom * Scale.y >= ScaleMin.y && zoom * Scale.x <= ScaleMax.x && zoom * Scale.y <= ScaleMax.y)
	{
		pView->zoom(zoom);

		if (pView->getSize().x > PosMax.x - PosMin.x)
		{
			pView->zoom((PosMax.x - PosMin.x) / pView->getSize().x);
			pView->setCenter(PosMin.x + 0.5f*PosMax.x, pView->getCenter().y);
		}
		if (zoom * pView->getSize().y > PosMax.y - PosMin.y)
		{
			pView->zoom((PosMax.y - PosMin.y) / pView->getSize().y);
			pView->setCenter(pView->getCenter().x, PosMin.y + 0.5f*PosMax.y);
		}
		updatescale();
	}
}

void Camera::updatescale()
{
	sf::Vector2u Size = rw->getSize();
	sf::Vector2f size = rw->getView().getSize();
	Scale = sf::Vector2f(size.x / float(Size.x), size.y / float(Size.y));
}
