#pragma once

#include "Widget.h"

namespace gui
{
	class Checkbox : public gui::Widget
	{
	public:
		Checkbox(bool initState);
		~Checkbox();

		void handleEvent(sf::Event e, sf::RenderWindow *rw)	override;
		void render(sf::RenderWindow *rw)					override;
		void setPosition(sf::Vector2f pos, bool withcoords)	override;
		bool getBool()										override;

		sf::Vector2f getPosition()							override;
		sf::Vector2f getPositionCoords()					override;
	private:
		Rectangel	*pCheckbox;

		sf::Vector2f mPosition, mPosCoords;

		sf::Color OnHover, OnClick, OnDefault, OffHover, OffClick, OffDefault;

		bool Clicked;
	};
}
