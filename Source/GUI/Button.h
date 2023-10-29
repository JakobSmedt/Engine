#pragma once

#include <functional>

#include "Widget.h"

namespace gui
{
	enum ButtonSize
	{
		Wide, Small
	};

	class Button : public gui::Widget
	{
	public:
		Button(ButtonSize s);
		~Button();

		void handleEvent(sf::Event e, sf::RenderWindow *rw)	override;
		void render(sf::RenderWindow *rw)					override;

		void setPosition(sf::Vector2f pos, bool withcoords)	override;
		void setScale(sf::Vector2f scale)					override;
		void setFunction(std::function<void(void)> func)	override;
		void setText(std::string str)						override;
		void setTexture(sf::Texture *txr)					override;
		void setSoundBuffer(sf::SoundBuffer *sfx)			override;
		void setVolume(float F)								override;

		sf::Vector2f getSize()								override;
		sf::Vector2f getPosition()							override;
		sf::Vector2f getPositionCoords()					override;

	private:
		void UpdateText();

		Text		*pText;
		Rectangel	*pButton;

		sf::Sound *pClickSound;
		sf::Sound *pHoverSound;

		sf::Vector2f mPosition, mPosCoords, mScale;

		sf::Color OnHover, OnClick, Default;

		std::function<void(void)> mfunction = [](){};

		bool hover;
	};

	//inline std::unique_ptr<Button> makeButton() { return std::make_unique<Button>(); }
}
