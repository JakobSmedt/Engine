#include "Label.h"

namespace gui
{
	Label::Label(std::string text)
	{
		pText = new Text;
		pText->setString(text);
	}

	Label::~Label()
	{
		delete pText;

		pText = nullptr;
	}

	void Label::render(sf::RenderWindow *rw)
	{
		rw->draw(*pText);
	}

	void Label::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pText->setPosition(pos);
	}

	void Label::setText(std::string str)
	{
		pText->setString(str);
	}
	sf::Vector2f Label::getPosition()
	{
		return mPosition;
	}
	sf::Vector2f Label::getPositionCoords()
	{
		return mPosCoords;
	}
}
