#include "../RescoureManager/ResourceHolder.h"
#include "Widget.h"


namespace gui
{
	Widget::Text::Text()
	{
		setCharacterSize(25);
		setOutlineColor(sf::Color::Black);
		setFillColor(sf::Color::White);
		setFont(*ResourceHolder::get().font.get("arial"));
	}

	Widget::Rectangel::Rectangel()
	{
		setFillColor(sf::Color::Black);
	}

	bool Widget::Rectangel::onHover(sf::RenderWindow * rw)
	{
		return getGlobalBounds().contains(rw->mapPixelToCoords(sf::Mouse::getPosition(*rw)));
	}

	bool Widget::Rectangel::onClicked(sf::Event e, sf::RenderWindow *rw)
	{
		if (onHover(rw))
			if (e.type == sf::Event::MouseButtonPressed)
				return e.mouseButton.button == sf::Mouse::Left;
		return false;
	}

	bool Widget::Rectangel::onReleased(sf::Event e, sf::RenderWindow * rw)
	{
		if (onHover(rw))
			if (e.type == sf::Event::MouseButtonReleased)
				return e.mouseButton.button == sf::Mouse::Left;
		return false;
	}

}
