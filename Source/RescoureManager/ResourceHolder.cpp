#include "ResourceHolder.h"

ResourceHolder& ResourceHolder::get()
{
	static ResourceHolder Holder;
	return Holder;
}

ResourceHolder::ResourceHolder()
	: font			("res/fonts/", ".ttf")
	, texture		("res/txrs/", ".png")
	, soundbuffer	("res/sfx/", ".ogg")
{ }