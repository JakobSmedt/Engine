#pragma once

#include <string>

#include "Widget.h"

namespace gui
{
	class TextBox : public gui::Widget
	{
	public:
		TextBox(std::string initText);
		~TextBox();

		void handleEvent(sf::Event e, sf::RenderWindow *rw)	override;
		void render(sf::RenderWindow *rw)					override;
		void setPosition(sf::Vector2f pos, bool withcoords)	override;

		std::string getText()								override;
		sf::Vector2f getPosition()							override;
		sf::Vector2f getPositionCoords()					override;

	private:
		void handleClick(sf::Event e, sf::RenderWindow *rw);
		void handleTextInput(sf::Event e);

		bool isValidCharacter(unsigned char keyCode);
		bool isBackspace(unsigned char keycode);

		Text		*pText;
		Text		*pInitText;
		Rectangel	*pTextBox;

		sf::Vector2f mPosition, mPosCoords;

		std::string EnteredText;
		bool mIsActive;
	};

	//inline std::unique_ptr<TextBox> makeTextBox(std::string& modStr) { return std::make_unique<TextBox>(modStr); }
}

/*
class TextBox : public gui::Widget
	{
		public:
			TextBox(std::string& modString);

			void setLabel       (const std::string& str);
			void setTexture     (const sf::Texture& tex);

			sf::Vector2f getSize() const override;

		private:
			Text m_label;
	};
*/