#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"

class StateManager
{
public:
	StateManager(sf::RenderWindow *p_rw);
	~StateManager();

	template<typename T, typename... Args>
	void pushState(std::string name, Args&&... args);
	void pushState(std::string name, std::unique_ptr<BaseState> state);

	void handleEvent(sf::Event e);
	void handleInput();
	void update(float frametime);
	void fixedUpdate(float frametime);
	void render();

	void nextState(std::string stateid);
	void deleteState(std::string stateid);

	void setVolume(float f);

	bool getQuit() { return quit; }
	void Quit() { quit = true; };

private:
	void eraseState();

	std::unordered_map<std::string, std::unique_ptr<BaseState>> mStates;

	sf::RenderWindow *rw;

	std::string mCurrentState;

	std::vector<std::string> toDelete;

	float volume = 100.0f;
	bool quit = false;
};

template<typename T, typename... Args>
inline void StateManager::pushState(std::string name, Args&&... args)
{
	pushState(name, std::make_unique<T>(std::forward<Args>(args)...));
}