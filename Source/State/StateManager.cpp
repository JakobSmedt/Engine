#include "../RescoureManager/ResourceHolder.h"
#include "../framework.h"
#include "StateManager.h"


StateManager::StateManager(sf::RenderWindow *p_rw)//, framework *p_fw
	: rw(p_rw)
	//, pFramework(p_fw)
{
	pushState<SplashState>("SplashState_0", rw, this);

	mCurrentState = "SplashState_0";
}

StateManager::~StateManager()
{

}

void StateManager::pushState(std::string name, std::unique_ptr<BaseState> state)
{
	mStates.insert({ name, std::move(state) });
	mStates.at(name)->setVolume(volume);
}

void StateManager::handleEvent(sf::Event e)
{
	mStates.at(mCurrentState)->handleEvent(e);
}

void StateManager::handleInput()
{
	mStates.at(mCurrentState)->handleInput();
}

void StateManager::update(float frametime)
{
	eraseState();

	mStates.at(mCurrentState)->update(frametime);
}

void StateManager::fixedUpdate(float frametime)
{
	mStates.at(mCurrentState)->fixedUpdate(frametime);
}

void StateManager::render()
{
	mStates.at(mCurrentState)->render();//rw
}

void StateManager::nextState(std::string stateid)
{
	if (mStates.find(stateid) != mStates.end())
		mCurrentState = stateid;
}

void StateManager::deleteState(std::string stateid)
{
	if (mStates.find(stateid) != mStates.end())
		toDelete.push_back(stateid);
}

void StateManager::eraseState()
{
	for (auto it = toDelete.begin(); it != toDelete.end(); it++)
	{
		mStates.erase(*(it));
	}
	
	toDelete.clear();
}

void StateManager::setVolume(float f)
{
	volume = f;
	for (auto it = mStates.begin(); it != mStates.end(); ++it)
	{
		it->second->setVolume(volume);
	}
}


