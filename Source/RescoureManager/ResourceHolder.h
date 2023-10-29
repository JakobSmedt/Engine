#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Resource.h"
#include "../Util/NonCopyable.h"
#include "../Util/NonMoveable.h"

class ResourceHolder : public NonCopyable, public NonMovable
{
public:
	static ResourceHolder &get();

	Resource<sf::Font>			font;
	Resource<sf::Texture>		texture;
	Resource<sf::SoundBuffer>	soundbuffer;
private:
	ResourceHolder();
};

