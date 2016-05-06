#pragma once

namespace cdgdecode
{

struct ColorEncodingHighByte
{
	unsigned char green : 2
	unsigned char red : 4;
	unsigned char X : 2;
};


struct ColorEncodingLowByte
{
	unsigned char blue : 4;
	unsigned char green : 2;
	unsigned char X : 2;
};


}


