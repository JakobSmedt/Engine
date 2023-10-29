#include "TextureAnimation.h"


TextureAnimation::TextureAnimation(unsigned frameWidth, unsigned frameHeight)
	: FRAME_WIDTH(frameWidth)
	, FRAME_HEIGTH(frameHeight)
{
	mTimer.restart();
}

void TextureAnimation::addFrame(sf::Time delay)//unsigned index, 
{
	unsigned index = mFrames.size();

	sf::IntRect bounds(index*FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGTH);

	mFrames.emplace_back(bounds, delay);
}

void TextureAnimation::addUniform(unsigned number, sf::Time delay)
{
	unsigned size = mFrames.size();

	for (unsigned index = 0; index < number; index++)
	{
		sf::IntRect bounds((size + index)*FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGTH);

		mFrames.emplace_back(bounds, delay);
	}
}

sf::IntRect* TextureAnimation::getFrame()
{
	mElapsedTime += mTimer.getElapsedTime();

	while (mElapsedTime >= mFrames[currentFrame].delay)
	{
		mElapsedTime -= mFrames[currentFrame].delay;
		currentFrame = (currentFrame + 1) % mFrames.size();
	}

	mTimer.restart();

	return &(mFrames[currentFrame % mFrames.size()].bounds);
}
