#pragma once

/**
 * This struct is based on information from the CD+G revealed 
 * document. It is an interpretation of what they have put 
 * together.
 */

#include <cstdint>


namespace cdgdecode
{

struct SubCode
{
	std::int8_t command;
	std::int8_t instruction;
	std::int8_t parityQ[2];
	std::int8_t data[16];
	std::int8_t parityP[4];
};


/**
 * Inside of the documentation it maps bit locations to a 
 * channel. To Simplify how this works, I've created a struct that
 * performs bit-packing. 
 */
struct ChannelMapping
{
	unsigned char W : 1;
	unsigned char V : 1;
	unsigned char U : 1;
	unsigned char T : 1;
	unsigned char S : 1;
	unsigned char R : 1;
	unsigned char Q : 1;
	unsigned char P : 1;
};


/**
 * To use this feature, simply instantiate this union object, assign
 * the data member, then query the channel.
 */
union ChannelDecoder
{
	ChannelMapping channel;
	std::int8_t data;
};

}

