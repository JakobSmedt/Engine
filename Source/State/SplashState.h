#pragma once

#include "BaseState.h"

class SplashState : public BaseState
{
public:
	SplashState(sf::RenderWindow *p_rw, StateManager *p_sm);
	~SplashState();

	void handleEvent(sf::Event e)				override;
	void handleInput()							override;
	void update(float frametime)				override;
	void fixedUpdate(float frametime)			override;
	void render()								override;

private:
	void ToMenu();

	sf::Sprite *pTitelscreen;

	float Time, stayontime, fadetime;
};
