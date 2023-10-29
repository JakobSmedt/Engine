#include "TextBox.h"
#include <iostream>

namespace gui
{
	TextBox::TextBox(std::string initText)
		: EnteredText ("")
		, mIsActive   (false)
	{

		pText = new Text;
		//pText->setCharacterSize(15);

		pInitText = new Text;
		pInitText->setFillColor({ 192, 192, 192 });
		pInitText->setString(initText);

		pTextBox  = new Rectangel;
		pTextBox->setFillColor({ 52, 152, 219 });
		pTextBox->setSize({ 256, 64 });

	}

	TextBox::~TextBox()
	{
		delete pTextBox;
		delete pInitText;
		delete pText;

		pTextBox  = nullptr;
		pInitText = nullptr;
		pText     = nullptr;
	}

	void TextBox::handleEvent(sf::Event e, sf::RenderWindow *rw)
	{
		handleClick(e, rw);
		handleTextInput(e);
	}

	void TextBox::render(sf::RenderWindow * rw)
	{

		if (!mIsActive)
			pTextBox->setFillColor({ 52, 152, 219 });
		else
			pTextBox->setFillColor({ 82, 132, 239 });

		rw->draw(*pTextBox);

		if (EnteredText == "")
			rw->draw(*pInitText);
		else
		rw->draw(*pText);
	}

	void TextBox::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pText->setPosition(pos);
		pText->move(5, (pTextBox->getGlobalBounds().height - pText->getCharacterSize()) / 2.0f);
		pInitText->setPosition(pos);
		pInitText->move(5, (pTextBox->getGlobalBounds().height - pInitText->getCharacterSize()) / 2.0f);
		pTextBox->setPosition(pos);
	}

	std::string TextBox::getText()
	{
		return pText->getString();
	}

	sf::Vector2f TextBox::getPosition()
	{
		return mPosition;
	}

	sf::Vector2f TextBox::getPositionCoords()
	{
		return mPosCoords;
	}

	void TextBox::handleClick(sf::Event e, sf::RenderWindow *rw)
	{
		auto pos = sf::Mouse::getPosition(*rw);
		if (e.type = sf::Event::MouseButtonReleased)
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				if (pTextBox->getGlobalBounds().contains((float)pos.x, (float)pos.y))
					mIsActive = true;
				else
					mIsActive = false;
			}
	}

	void TextBox::handleTextInput(sf::Event e)
	{
		if (mIsActive)
		{
			switch (e.type)
			{
			case sf::Event::TextEntered:
			{
				unsigned char keyCode = e.text.unicode;

				if (isValidCharacter(keyCode))
				{
					if (pText->getGlobalBounds().width + 30 <= pTextBox->getGlobalBounds().width)
						EnteredText.push_back(keyCode);
				}
				else if (isBackspace(keyCode))
					if (EnteredText.length() > 0)
						EnteredText.pop_back();

				pText->setString(EnteredText);
				break;
			}
			default:
				break;
			}
		}
	}

	bool TextBox::isValidCharacter(unsigned char keyCode)
	{
		//std::cout << static_cast<unsigned int>(keyCode) << std::endl;
		return keyCode >= 32 && keyCode <= 126 ||	//Space, Letter, Numbers and Special Charaters
			keyCode == 246 || keyCode == 214 ||		//ü Ü
			keyCode == 252 || keyCode == 220 ||		//ö Ö
			keyCode == 228 || keyCode == 196;		//ä Ä
	}

	bool TextBox::isBackspace(unsigned char keycode)
	{
		return keycode == 8;
	}
}

/*
void TextBox::setLabel(const std::string& str)
{
	m_label.setString(str);
}
void TextBox::render(sf::RenderTarget& renderer)
{
	renderer.draw(m_label);
}
void TextBox::setPosition(const sf::Vector2f& pos)
{
	m_label.setPosition(m_position.x,
						m_position.y + m_label.getGlobalBounds().height -
									   m_rect.getGlobalBounds().height / 2);
}
sf::Vector2f TextBox::getSize() const
{
	return  {m_rect.getSize().x,
			 m_rect.getSize().y + m_label.getGlobalBounds().height};
}*/