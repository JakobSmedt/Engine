#include "../RescoureManager/ResourceHolder.h"
#include "FPS_Counter.h"


FPS::FPS()
{
	pUpdateC = new sf::Clock;
	pUpdateC->restart();

	pFPS = new sf::Text("FPS: 0", *ResourceHolder::get().font.get("arial"));
	pFPS->setFillColor(sf::Color::Yellow);

	framecount = 0;
	UpdateTime = 1.f;
}

FPS::~FPS()
{
	delete pFPS;
	delete pUpdateC;

	pFPS     = nullptr;
	pUpdateC = nullptr;
}

void FPS::update()
{
	framecount++;

	if (pUpdateC->getElapsedTime().asSeconds() >= UpdateTime)
	{
		pFPS->setString("FPS: " + std::to_string(int(framecount / pUpdateC->getElapsedTime().asSeconds())));
		framecount = 0;
		pUpdateC->restart();
	}

	/*
	if (m_delayTimer.getElapsedTime().asSeconds() > 0.2) {
        m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
        m_frameCount = 0;
        m_delayTimer.restart();
    }
	*/
}

void FPS::render(sf::RenderWindow *rw)
{
	pFPS->setPosition(rw->mapPixelToCoords(sf::Vector2i(0, 0)));
	sf::Vector2u Size = rw->getSize();
	sf::Vector2f size = rw->getView().getSize();
	pFPS->setScale(sf::Vector2f(size.x/float(Size.x), size.y / float(Size.y)));

	rw->draw(*pFPS);
}
