#include "Globalvar.h"

Globalvar & Globalvar::get()
{
	static Globalvar holder;
	return holder;
}
