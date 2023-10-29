#include "../RescoureManager/ResourceHolder.h"
#include <iostream>
#include "Button.h"

namespace gui
{
	Button::Button(ButtonSize s)
	{
		pText = new Text;
		pButton = new Rectangel;

		pButton->setOutlineThickness(1.0f);
		//pButton->setOutlineColor(sf::Color::Green);
		//pButton->setFillColor(sf::Color::Black);

		OnHover = sf::Color(153, 153, 102);
		OnClick = sf::Color::White;
		Default = sf::Color::Black;

		pButton->setFillColor(Default);
		
		switch (s)
		{
		case gui::Wide:
			pButton->setSize({ 256, 64 });
			break;

		case gui::Small:
			pButton->setSize({ 128, 64 });
			break;
		}

		pClickSound = new sf::Sound;
		pHoverSound = new sf::Sound(*ResourceHolder::get().soundbuffer.get("ButtonHover"));

		mScale = sf::Vector2f(1.f, 1.f);

		hover = false;
	}
	
	Button::~Button()
	{
		delete pClickSound;
		delete pButton;
		delete pText;

		pClickSound = nullptr;
		pButton     = nullptr;
		pText       = nullptr;
	}

	void Button::handleEvent(sf::Event e, sf::RenderWindow *rw)
	{
		if (pButton->onReleased(e, rw))
		{
			if (pClickSound->getBuffer() != nullptr)
				pClickSound->play();
			mfunction();
		}
		else if (pButton->onClicked(e, rw))
		{
			if (pButton->getTexture() != nullptr)
			{
				pButton->setFillColor(sf::Color::White);
				pButton->setTextureRect(sf::IntRect(0, 2 * pButton->getTexture()->getSize().y / 3,
					pButton->getTexture()->getSize().x, pButton->getTexture()->getSize().y / 3));
			}
			else
				pButton->setFillColor(OnClick);
		}
		else if (pButton->onHover(rw))
		{
			if (pHoverSound->getBuffer() != nullptr && !hover)
					pHoverSound->play();
			if (pButton->getTexture() != nullptr)
			{
				pButton->setFillColor(sf::Color::White);
				pButton->setTextureRect(sf::IntRect(0, pButton->getTexture()->getSize().y / 3,
					pButton->getTexture()->getSize().x, pButton->getTexture()->getSize().y / 3));
			}
			else
			{
				pButton->setFillColor(OnHover);
			}
			hover = true;
		}
		else
		{
			hover = false;
			if (pButton->getTexture() != nullptr)
			{
				pButton->setFillColor(sf::Color::White);
				pButton->setTextureRect(sf::IntRect(0, 0,
					pButton->getTexture()->getSize().x, pButton->getTexture()->getSize().y / 3));
			}
			else
				pButton->setFillColor(Default);
		}
	}

	void Button::render(sf::RenderWindow * rw)
	{
		rw->draw(*pButton);
		rw->draw(*pText);
	}

	void Button::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pButton->setPosition(pos);
		pText->setPosition(pos);

		UpdateText();
	}

	void Button::setScale(sf::Vector2f scale)
	{
		mScale = scale;

		pButton->setScale(mScale);
		pText->setScale(mScale);

		//Hierhigehend anpassen
		//UpdateText();
	}

	void Button::setFunction(std::function<void(void)> func)
	{
		mfunction = func;
	}

	void Button::setText(std::string str)
	{
		pText->setString(str);
		UpdateText();
	}

	void Button::setTexture(sf::Texture *txr)
	{
		pButton->setTexture(txr);
		if (pButton->getTexture() != nullptr)
		{
			pButton->setTextureRect(sf::IntRect(0, 0,
				pButton->getTexture()->getSize().x, pButton->getTexture()->getSize().y / 3));
		}
	}

	void Button::setSoundBuffer(sf::SoundBuffer *sfx)
	{
		pClickSound->setBuffer(*sfx);
	}

	void Button::setVolume(float F)
	{
		pClickSound->setVolume(F);
		pHoverSound->setVolume(F);
	}

	sf::Vector2f Button::getSize()
	{
		return pButton->getSize();
	}

	sf::Vector2f Button::getPosition()
	{
		return mPosition;
	}

	sf::Vector2f Button::getPositionCoords()
	{
		return mPosCoords;
	}

	void Button::UpdateText()
	{
		pText->setOrigin(pText->getGlobalBounds().width / 2,
			pText->getGlobalBounds().height / 2);

		pText->move(pButton->getGlobalBounds().width / 2.0f,
			pButton->getGlobalBounds().height / 2.5f);
		//std::cout << (pButton->getGlobalBounds().width / 2.0f)/ pButton->getScale().x << "\t" << pButton->getScale().x << std::endl;
	}
}
