#pragma once

#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Util/NonCopyable.h"

namespace gui
{
	class Widget : NonCopyable
	{
	public:
		Widget() {};

		~Widget() = default;

		virtual void handleEvent(sf::Event e, sf::RenderWindow *rw) {}
		virtual void handleInput() {}
		virtual void update(float frametime) {}
		virtual void fixedUpdate(float frametime) {}
		virtual void render(sf::RenderWindow *rw) {}

		virtual void setPosition(sf::Vector2f pos, bool withcoords = true) {}
		virtual void setScale(sf::Vector2f scale) {}
		virtual void setText(std::string text) {}
		virtual void setFunction(std::function<void(void)> func) {}
		virtual void setTexture(sf::Texture *txr) {}
		virtual void setSoundBuffer(sf::SoundBuffer *sfx) {}
		virtual void setFloat(float F) {}
		virtual void setVolume(float F) {}

		virtual sf::Vector2f getSize()				{ return sf::Vector2f(0.0f, 0.0f); };
		virtual sf::Vector2f getPosition()			{ return sf::Vector2f(0.0f, 0.0f); };
		virtual sf::Vector2f getPositionCoords()	{ return sf::Vector2f(0.0f, 0.0f); };
		virtual std::string getText()				{ return ""; };
		virtual bool getBool()						{ return false; };
		virtual float getFloat()					{ return 0.0f; };

	protected:

		class Text : public sf::Text
		{
		public:
			Text();
		};

		class Rectangel : public sf::RectangleShape
		{
		public:
			Rectangel();

			bool onHover(sf::RenderWindow *rw);
			bool onClicked(sf::Event e, sf::RenderWindow *rw);
			bool onReleased(sf::Event e, sf::RenderWindow *rw);
		};
	};
}
