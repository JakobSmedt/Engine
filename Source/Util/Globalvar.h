#pragma once

#include "NonCopyable.h"
#include "NonMoveable.h"

class Globalvar : public NonCopyable, public NonMovable
{
public:
	static Globalvar& get();

	bool quit = false;
};