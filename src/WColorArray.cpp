#include "WColorArray.h"

WColorArray::WColorArray(unsigned char r,unsigned char g,unsigned char b,int size)
{
	this->size = size;
	
	this->colors = new WColor[this->size];
	
	for(int i=0;i<size;i++)
	{
		colors[i].r = r;
		colors[i].g = g;
		colors[i].b = b;
	}
}

WColorArray::WColorArray(const WColorArray &colors)
{
	*this = colors;
}

WColorArray::WColorArray(const char *colors)
{
	this->size = strlen(colors);
	this->colors = new WColor[this->size];

	for(int i=0;i<this->size;i++)
	{
		switch(colors[i])
		{
			case 'r':
				this->colors[i].r = 0xff;
				this->colors[i].g = 0x00;
				this->colors[i].b = 0x00;
				break;
			case 'g':
				this->colors[i].r = 0x00;
				this->colors[i].g = 0xff;
				this->colors[i].b = 0x00;
				break;
			case 'b':
				this->colors[i].r = 0x00;
				this->colors[i].g = 0x00;
				this->colors[i].b = 0xff;
				break;
			case 'w':
				this->colors[i].r = 0xff;
				this->colors[i].g = 0xff;
				this->colors[i].b = 0xff;
				break;
			case ' ':
			default:
				this->colors[i].r = 0x00;
				this->colors[i].g = 0x00;
				this->colors[i].b = 0x00;
				break;
		}
	}
	
}

WColorArray::~WColorArray()
{
	delete colors;
}

WColorArray& WColorArray::operator=(const WColorArray&colors)
{
	delete this->colors;

	this->colors = new WColor[colors.size];
	
	for(int i=0;i<colors.size;i++)
	{
		this->colors[i] = colors.colors[i];
	}
	
	return *this;
}


