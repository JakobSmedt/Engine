#include "Checkbox.h"

namespace gui
{
	Checkbox::Checkbox(bool initState)
		: Clicked(initState)
	{
		pCheckbox = new Rectangel;
		pCheckbox->setOutlineThickness(1.0f);
		pCheckbox->setOutlineColor(sf::Color::White);

		OffHover = sf::Color(153, 153, 102);
		OffClick = sf::Color::White;
		OffDefault = sf::Color::Black;
		OnHover = sf::Color(107, 255, 109);
		OnClick = sf::Color::White;
		OnDefault = sf::Color::Green;

		if (Clicked)
			pCheckbox->setFillColor(OnDefault);
		else
			pCheckbox->setFillColor(OffDefault);

		pCheckbox->setSize({ 64, 64 });
	}

	Checkbox::~Checkbox()
	{
		delete pCheckbox;

		pCheckbox = nullptr;
	}

	void Checkbox::handleEvent(sf::Event e, sf::RenderWindow * rw)
	{
		if (pCheckbox->onReleased(e, rw))
		{
			Clicked = !Clicked;
		}
		else if (pCheckbox->onClicked(e, rw))
		{
			if (pCheckbox->getTexture() != nullptr)
			{
				pCheckbox->setFillColor(sf::Color::White);
				pCheckbox->setTextureRect(sf::IntRect(0, 2 * pCheckbox->getTexture()->getSize().y / 3,
					pCheckbox->getTexture()->getSize().x, pCheckbox->getTexture()->getSize().y / 3));
			}
			else
			{
				if (Clicked)
					pCheckbox->setFillColor(OnClick);
				else
					pCheckbox->setFillColor(OffClick);
			}
		}
		else if (pCheckbox->onHover(rw))
		{
			if (pCheckbox->getTexture() != nullptr)
			{
				pCheckbox->setFillColor(sf::Color::White);
				pCheckbox->setTextureRect(sf::IntRect(0, pCheckbox->getTexture()->getSize().y / 3,
					pCheckbox->getTexture()->getSize().x, pCheckbox->getTexture()->getSize().y / 3));
			}
			else
			{
				if (Clicked)
					pCheckbox->setFillColor(OnHover);
				else
					pCheckbox->setFillColor(OffHover);
			}
		}
		else
		{
			if (pCheckbox->getTexture() != nullptr)
			{
				pCheckbox->setFillColor(sf::Color::White);
				pCheckbox->setTextureRect(sf::IntRect(0, 0,
					pCheckbox->getTexture()->getSize().x, pCheckbox->getTexture()->getSize().y / 3));
			}
			else
			{
				if (Clicked)
					pCheckbox->setFillColor(OnDefault);
				else
					pCheckbox->setFillColor(OffDefault);
			}
		}
	}

	void Checkbox::render(sf::RenderWindow *rw)
	{
		rw->draw(*pCheckbox);
	}

	void Checkbox::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pCheckbox->setPosition(pos);
	}

	bool Checkbox::getBool()
	{
		return Clicked;
	}
	sf::Vector2f Checkbox::getPosition()
	{
		return mPosition;
	}
	sf::Vector2f Checkbox::getPositionCoords()
	{
		return mPosCoords;
	}
}