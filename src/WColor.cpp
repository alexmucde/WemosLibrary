#include "WColor.h"

WColor::WColor(unsigned char r,unsigned char g,unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

WColor::WColor(const WColor &color)
{
	*this = color;
}

WColor::~WColor()
{
}

WColor& WColor::operator=(const WColor &color)
{
	r=color.r;
	g=color.g;
	b=color.b;
	
	return *this;
}


