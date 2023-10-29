#include "Util/Globalvar.h"
#include "RescoureManager/ResourceHolder.h"
#include "framework.h"

framework::framework()
{
	pRenderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Titel", sf::Style::Default);
	//pRenderWindow->setFramerateLimit(60);
	pMainEvent    = new sf::Event;

	pStatemanager = new StateManager(pRenderWindow);//, this

	pframetimeclock = new sf::Clock;
	pframetimeclock->restart();

	pfixedframetimeclock = new sf::Clock;
	pfixedframetimeclock->restart();

	pFPS = new FPS;

	mIsRunning = true;

	TPS = 30;
	timePerUpdate = 1.0f / float(TPS);
	lag = 0.0f;
}

framework::~framework()
{
	delete pFPS;
	delete pfixedframetimeclock;
	delete pframetimeclock;
	delete pStatemanager;
	delete pMainEvent;
	delete pRenderWindow;

	pFPS					= nullptr;
	pfixedframetimeclock	= nullptr;
	pframetimeclock			= nullptr;
	pStatemanager			= nullptr;
	pMainEvent				= nullptr;
	pRenderWindow			= nullptr;
}

void framework::run()
{
	while (mIsRunning)
	{
		float frametime = calcframetime();
		lag += frametime;

		update(frametime);
		while (lag >= timePerUpdate)
		{
			lag -= timePerUpdate;
			float fixedFrametime = pfixedframetimeclock->restart().asSeconds();
			fixedUpdate(fixedFrametime);
			//std::cout << "Now: " << fixedFrametime << std::endl;
		}
		handel();
		render();

		quit();
	}
}

void framework::update(float frametime)
{
	pStatemanager->update(frametime);
	pFPS->update();
}

void framework::fixedUpdate(float frametime)
{
	pStatemanager->fixedUpdate(frametime);
}

void framework::handel()
{
	while (pRenderWindow->pollEvent(*pMainEvent))
	{
		if (pMainEvent->type == sf::Event::Closed)
			mIsRunning = false;;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			mIsRunning = false;;
		pStatemanager->handleEvent(*pMainEvent);
	}

	pStatemanager->handleInput();
}

void framework::render()
{
	pRenderWindow->clear();

	pStatemanager->render();

	pFPS->render(pRenderWindow);
	pRenderWindow->display();
}

void framework::quit()
{
	if (pStatemanager->getQuit())
		mIsRunning = false;
}

float framework::calcframetime()
{
	float frametime = pframetimeclock->getElapsedTime().asSeconds();
	pframetimeclock->restart();
	return frametime;
}
