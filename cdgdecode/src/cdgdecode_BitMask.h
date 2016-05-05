#pragma once

#include <cstdint>

namespace cdgdecode
{

struct SplitMask
{
	unsigned char upper : 4;
	unsigned char lower : 4;
};

union BitMask
{
	std::int8_t data;
	SplitMask upperLower;
};


struct Lower4
{
	unsigned char lower4 : 4;
	unsigned char upper4 : 4;
};

struct Lower5
{
	unsigned char lower5 : 5;
	unsigned char lower3 : 3;
};

struct Lower6
{
	unsigned char lower6 : 6;
	unsigned char lower2 : 2;
};


struct DrawingBits
{
	unsigned char rest : 2;

	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;

};


union TileBlockChannel
{
	std::int8_t data;
	Lower4 l4;
	Lower5 l5;
	Lower6 l6;
	DrawingBits drawing;
};



};

