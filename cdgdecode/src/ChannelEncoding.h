#pragma once

namespace cdgdecode
{


/**
 * Inside of the documentation it maps bit locations to a 
 * channel. To Simplify how this works, I've created a struct that
 * performs bit-packing. 
 */
struct ChannelEncoding
{
	unsigned char W : 1;   // bit 0
	unsigned char V : 1;   // bit 1
	unsigned char U : 1;   // bit 2
	unsigned char T : 1;   // bit 3
	unsigned char S : 1;   // bit 4
	unsigned char R : 1;   // bit 5
	unsigned char Q : 1;   // bit 6
	unsigned char P : 1;   // bit 7
};



}
