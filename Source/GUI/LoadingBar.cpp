#include "LoadingBar.h"

namespace gui
{
	LoadingBar::LoadingBar(float finishtimesec)
	{
		pBox = new Rectangel;
		pBar = new Rectangel;

		pBox->setSize({ 256, 32 });
		pBar->setSize({ finishtimesec * 246, 22 });

		pBox->setOutlineThickness(1.0f);
		pBar->setOutlineThickness(1.0f);
	}

	LoadingBar::~LoadingBar()
	{
		delete pBar;
		delete pBox;

		pBar = nullptr;
		pBox = nullptr;
	}

	void LoadingBar::update(float frametime)
	{

	}

	void LoadingBar::render(sf::RenderWindow *rw)
	{
		rw->draw(*pBox);
		rw->draw(*pBar);
	}

	void LoadingBar::setPosition(sf::Vector2f pos, bool withcoords)
	{
		mPosition = pos;
		if (withcoords)
			mPosCoords = mPosition;

		pBox->setPosition(mPosition);
		pBar->setPosition(mPosition);
		pBar->move(5.0f, 5.0f);
	}

	void LoadingBar::setTexture(sf::Texture *txr)
	{

	}

	void LoadingBar::setFloat(float F)
	{

	}

	sf::Vector2f LoadingBar::getSize()
	{
		return sf::Vector2f(mPosition);
	}

	sf::Vector2f LoadingBar::getPosition()
	{
		return mPosition;
	}
	sf::Vector2f LoadingBar::getPositionCoords()
	{
		return mPosCoords;
	}
}
