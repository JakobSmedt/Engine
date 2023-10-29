#pragma once

#include <functional>
#include <unordered_map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "TextBox.h"
#include "Checkbox.h"
#include "ListBox.h"
#include "Slider.h"
#include "Label.h"
#include "LoadingBar.h"

namespace gui
{
	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow *p_rw);
		~GUIManager();

		template<typename T, typename... Args>
		void pushWidget(std::string name, Args&&... args);
		void pushWidget(std::string name, std::unique_ptr<Widget> state);

		void handleEvent(sf::Event e);
		void handleInput();
		void update(float frametime);
		void fixedUpdate(float frametime);
		void render();

		void setPositon(std::string name, sf::Vector2f pos)					{ mElements.at(name)->setPosition(pos); };
		void setText(std::string name, std::string text)					{ mElements.at(name)->setText(text); };
		void setFunction(std::string name, std::function<void(void)> func)	{ mElements.at(name)->setFunction(func); };
		void setTexture(std::string name, sf::Texture *txrs)				{ mElements.at(name)->setTexture(txrs); };
		void setSoundBuffer(std::string name, sf::SoundBuffer *sfx)			{ mElements.at(name)->setSoundBuffer(sfx); };
		void setFloat(std::string name, float f)							{ mElements.at(name)->setFloat(f); };

		void setVolume(float f)
		{
			for (auto it = mElements.begin(); it != mElements.end(); ++it)
			{
				it->second->setVolume(f);
			}
		};

		sf::Vector2f getPosition(std::string name)	{ return mElements.at(name)->getPosition(); };
		sf::Vector2f getSize(std::string name)		{ return mElements.at(name)->getSize(); };
		std::string getText(std::string name)		{ return mElements.at(name)->getText(); };
		bool getBool(std::string name)				{ return mElements.at(name)->getBool(); };
		float getFloat(std::string name)			{ return mElements.at(name)->getFloat(); };

	private:
		std::unordered_map<std::string, std::unique_ptr<gui::Widget>> mElements;

		sf::RenderWindow *rw;
	};

	template<typename T, typename... Args>
	inline void GUIManager::pushWidget(std::string name, Args&&... args)
	{
		pushWidget(name, std::make_unique<T>(std::forward<Args>(args)...));
	}
}
