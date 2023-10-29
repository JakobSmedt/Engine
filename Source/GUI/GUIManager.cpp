#include "GUIManager.h"

namespace gui
{
	GUIManager::GUIManager(sf::RenderWindow *p_rw)
		: rw(p_rw)
	{

	}

	GUIManager::~GUIManager()
	{

	}

	void GUIManager::pushWidget(std::string name, std::unique_ptr<gui::Widget> widget)
	{
		mElements.insert({ name, std::move(widget) });
	}

	void GUIManager::handleEvent(sf::Event e)
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			it->second->handleEvent(e, rw);
		}
	}

	void GUIManager::handleInput()
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			it->second->handleInput();
		}
	}

	void GUIManager::update(float frametime)
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			it->second->update(frametime);
		}
	}

	void GUIManager::fixedUpdate(float frametime)
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			it->second->fixedUpdate(frametime);
		}
	}

	void GUIManager::render()
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			sf::Vector2f pos = it->second->getPositionCoords();
			it->second->setPosition(rw->mapPixelToCoords(sf::Vector2i(int(pos.x), int(pos.y))), false);

			sf::Vector2u Size = rw->getSize();
			sf::Vector2f size = rw->getView().getSize();
			sf::Vector2f scale = sf::Vector2f(size.x / float(Size.x), size.y / float(Size.y));
			it->second->setScale(scale);


			it->second->render(rw);
		}
	}

}