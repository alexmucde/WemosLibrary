#ifndef W_COLOR_ARRAY
#define W_COLOR_ARRAY

#include "Arduino.h"

#include "WColor.h"

class WRgb;

class WColorArray
{
	friend WRgb;
	
	public:
		WColorArray(unsigned char r = 0xff,unsigned char g = 0xff,unsigned char b=0xff,int size = 1);
		WColorArray(const WColorArray &colors);
		WColorArray(const char *colors);
		~WColorArray();
		
		WColorArray& operator=(const WColorArray &colors);
		
	private:
		WColor* colors;
		int size;
	
};

#endif
