#ifndef W_COLOR
#define W_COLOR

class WRgb;
class WColorArray;

class WColor
{
	friend WRgb;
	friend WColorArray;
	
	public:
		WColor();
		WColor(unsigned char r,unsigned char g,unsigned char b);
		WColor(const WColor &color);
		~WColor();
		
		WColor& operator=(const WColor &color);
		
	private:
		unsigned char r,g,b;
	
};

const WColor black = WColor(0x00,0x00,0x00);
const WColor white = WColor(0xff,0xff,0xff);
const WColor red = WColor(0xff,0x00,0x00);
const WColor green = WColor(0x00,0xff,0x00);
const WColor blue = WColor(0x00,0x00,0xff);
const WColor orange = WColor(0xff,0xa5,0x00);
const WColor purple = WColor(0xa0,0x20,0xf0);

#endif
