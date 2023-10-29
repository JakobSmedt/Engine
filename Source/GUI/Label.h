#pragma once

#include "Widget.h"

namespace gui
{
	class Label : public gui::Widget
	{
	public:
		Label(std::string text);
		~Label();

		void render(sf::RenderWindow *rw)	override;

		void setPosition(sf::Vector2f pos, bool withcoords)	override;
		void setText(std::string str)						override;

		sf::Vector2f getPosition()			override;
		sf::Vector2f getPositionCoords()	override;
	private:
		Text *pText;

		sf::Vector2f mPosition, mPosCoords;
	};
}
