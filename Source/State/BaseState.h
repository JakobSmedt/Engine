#pragma once

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"

class StateManager;

/*enum NextState
{
	None, Splash, Menu
};*/

class BaseState : NonCopyable
{
public:
	BaseState(sf::RenderWindow *p_rw, StateManager *p_sm)
		: rw			(p_rw)
		, pStateManager	(p_sm)
	{ }

	virtual ~BaseState() = default;

	virtual void handleEvent(sf::Event e) {}
	virtual void handleInput() {}
	virtual void update(float frametime) {}
	virtual void fixedUpdate(float frametime) {}
	virtual void render() {}

	virtual void setVolume(float f) {}
protected:
	sf::RenderWindow *rw;

	StateManager *pStateManager;
};
