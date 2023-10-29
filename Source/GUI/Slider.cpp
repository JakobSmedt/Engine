#include "Slider.h"

namespace gui
{
	Slider::Slider(float initFloat)
		: prozent	(initFloat)
		, step		(float(0.00001))
	{
		pSliderControl = new Rectangel;
		pSliderControl->setFillColor(sf::Color(153, 153, 102));
		pSliderBar = new Rectangel;
		pSliderBar->setFillColor(sf::Color::White);

		pSliderBar->setSize({ 256, 16 });
		pSliderControl->setSize({ 16, 32 });
		pSliderControl->move(5 + prozent * (pSliderBar->getSize().x - 10), 0);
	}

	Slider::~Slider()
	{
		delete pSliderBar;
		delete pSliderControl;

		pSliderBar		= nullptr;
		pSliderControl	= nullptr;
	}

	void Slider::handleEvent(sf::Event e, sf::RenderWindow * rw)
	{
		auto mouse_y = sf::Mouse::getPosition(*rw).x;

		if (pSliderBar->onClicked(e, rw) || pSliderControl->onClicked(e, rw))
			movebel = true;

		if (movebel && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouse_y -= (int)pSliderBar->getPosition().x;
			prozent = (float)mouse_y / (pSliderBar->getSize().x);
			prozent = step * std::roundf(prozent / step);

			if (prozent <= 0.0f)
				prozent = 0.0f;
			else if (prozent >= 1.0f)
				prozent = 1.0f;

			setPosition(mPosition, true);
		}
		else
			movebel = false;
	}

	void Slider::render(sf::RenderWindow * rw)
	{
		rw->draw(*pSliderBar);
		rw->draw(*pSliderControl);
	}

	void Slider::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pSliderBar->setPosition(mPosition + sf::Vector2f(0, 8));
		pSliderControl->setPosition(mPosition);
		pSliderControl->move(prozent * (pSliderBar->getSize().x - 16), 0);
	}

	void Slider::setTexture(sf::Texture * txr)
	{
		// Kommt noch
	}

	void Slider::setFloat(float f)
	{
		step = f;
		prozent = step * std::roundf(prozent / step);
		setPosition(mPosition, true);
	}

	sf::Vector2f Slider::getSize()
	{
		return mPosition;
	}

	sf::Vector2f Slider::getPosition()
	{
		return mPosition;
	}

	sf::Vector2f Slider::getPositionCoords()
	{
		return mPosCoords;
	}

	float Slider::getFloat()
	{
		return prozent;
	}
}