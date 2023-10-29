#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

class TextureAnimation
{
public:
	TextureAnimation(unsigned frameWidth, unsigned frameHeight);

	void addFrame(sf::Time delay);//unsigned index, 
	void addUniform(unsigned number, sf::Time delay);

	void deleteFrames() { mFrames.clear(); };

	sf::IntRect* getFrame();

	struct Frame
	{
		Frame(sf::IntRect bnds, sf::Time dly)
			: bounds	(bnds)
			, delay		(dly)
		{ }

		sf::IntRect bounds;
		sf::Time delay;
	};

private:
	sf::Clock mTimer;
	sf::Time  mElapsedTime;

	std::vector<Frame> mFrames;

	unsigned FRAME_WIDTH, FRAME_HEIGTH;
	unsigned currentFrame = 0;
};
