#pragma once

#include "Widget.h"
#include <math.h>

namespace gui
{
	class Slider : public Widget
	{
	public:
		Slider(float initFloat);
		~Slider();

		void handleEvent(sf::Event e, sf::RenderWindow *rw)	override;
		void render(sf::RenderWindow *rw)					override;

		void setPosition(sf::Vector2f pos, bool withcoords)	override;
		void setTexture(sf::Texture *txr)					override;
		void setFloat(float f)								override;

		sf::Vector2f getSize()								override;
		sf::Vector2f getPosition()							override;
		sf::Vector2f getPositionCoords()					override;
		float getFloat()									override;
	private:
		Rectangel	*pSliderControl;
		Rectangel	*pSliderBar;

		sf::Vector2f mPosition, mPosCoords;

		float prozent;
		float step;
		bool movebel;
	};
}
