#pragma once

#include "Widget.h"

namespace gui
{
	class LoadingBar : public gui::Widget
	{
	public:
		 LoadingBar(float finishtimesec);
		~LoadingBar();

		void update(float frametime)		override;
		void render(sf::RenderWindow *rw)	override;

		void setPosition(sf::Vector2f pos, bool withcoords)	override;
		void setTexture(sf::Texture *txr)					override;
		void setFloat(float F)								override;

		sf::Vector2f getSize()				override;
		sf::Vector2f getPosition()			override;
		sf::Vector2f getPositionCoords()	override;
	private:
		Rectangel	*pBox;
		Rectangel	*pBar;

		sf::Vector2f mPosition, mPosCoords;
	};
}
