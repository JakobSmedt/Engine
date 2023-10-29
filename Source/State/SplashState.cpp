#include "../RescoureManager/ResourceHolder.h"
#include "StateManager.h"
#include "SplashState.h"


SplashState::SplashState(sf::RenderWindow *p_rw, StateManager *p_sm)
	: BaseState(p_rw, p_sm)
{
	pTitelscreen = new sf::Sprite(*ResourceHolder::get().texture.get("Titelscreen"));

	Time = 0.0f;
	stayontime = 3.0f;
	fadetime = 5.0f;
}

SplashState::~SplashState()
{
	delete pTitelscreen;

	pTitelscreen = nullptr;
}

void SplashState::handleEvent(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::KeyReleased:
		if (e.key.code == sf::Keyboard::Key::Enter)
			ToMenu();
		break;
	case sf::Event::MouseButtonReleased:
		if (e.mouseButton.button == sf::Mouse::Button::Left)
			ToMenu();
		break;
	default:
		break;
	}
}

void SplashState::handleInput()
{

}

void SplashState::update(float frametime)
{
	Time += frametime;

	if (int((255.0f / fadetime)*(fadetime - (Time - stayontime))) <= 0)
		ToMenu();
	else
		if (Time >= stayontime)
		{
			sf::Uint8 alpha = int((255.0f / fadetime)*(fadetime - (Time - stayontime)));
			pTitelscreen->setColor(sf::Color(pTitelscreen->getColor().a, pTitelscreen->getColor().g, pTitelscreen->getColor().b, alpha));
		}
}

void SplashState::fixedUpdate(float frametime)
{

}

void SplashState::render()
{
	rw->draw(*pTitelscreen);
}

void SplashState::ToMenu()
{
	pStateManager->pushState<MenuState>("Menu_0", rw, pStateManager);
	pStateManager->nextState("Menu_0");
	pStateManager->deleteState("SplashState_0");
}
