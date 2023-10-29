#pragma once

#include <functional>
#include <iostream>

#include "BaseState.h"
#include "../GUI/GUIManager.h"
#include "../Util/TextureAnimation.h"
#include "../Util/TCP_Connection.h"

class MenuState : public BaseState
{
public:
	MenuState(sf::RenderWindow *p_rw, StateManager *p_sm);
	~MenuState();

	void handleEvent(sf::Event e)				override;
	void handleInput()							override;
	void update(float frametime)				override;
	void fixedUpdate(float frametime)			override;
	void render()								override;

	void setVolume(float f)						override;

	void start();
	void setting();
	void ToogelMenu();
	void Apply();
private:
	void send();

	sf::Sprite *pAnim;

	gui::GUIManager *GUI_Manager;
	gui::GUIManager *GUI_Einstellungen;
	
	TextureAnimation *pTxrsAnim;

	sf::TcpSocket mSocket;

	int ShowSettings;
};

