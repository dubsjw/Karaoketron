#pragma once

/**
 * This struct is based on information from the CD+G revealed 
 * document. It is an interpretation of what they have put 
 * together.
 */

#include <cdgdecode/Globals.h>
#include "src/ChannelEncoding.h"

#include <cstdint>
#include <memory>

namespace cdgdecode
{

class CDGBuffer;

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
struct ChannelMask
{
	unsigned char payload : 6;
	unsigned char Q : 1;
	unsigned char P : 1;
};


/**
 * To use this feature, simply instantiate this union object, assign
 * the data member, then query the channel.
 */
union ChannelDecoder
{
	ChannelEncoding channel;
	ChannelMask mask;
	std::int8_t data;
};


struct PacketPrivate;

/**
 * The packet is an optimized holder of a SubCode. 
 */
struct CDGDECODE_EXPORT Packet 
{
	Packet(CDGBuffer const& buffer, std::uint32_t index);
	~Packet();
	Packet(Packet const& packet);
	Packet& operator=(Packet packet);
	void swap(Packet& packet);

	/**
	 * Read a different packet with random access from within the same
	 * buffer. The position is dictated by the index value.
	 *
	 * @param index The index into the buffer where we would read data.
	 */
	void ReloadAtPosition(std::uint32_t index);


	/**
	 * @return the command in the subcode without interpretation.
	 *         This could also include information not related to the 
	 *         cdg file format.
	 */
	std::int8_t RawCommand() const;


	/**
	 * @return true if the packet has CDG encoding. This is done 
	 *         through checking if the lower 6 bits of the 
	 */
	bool HasCDGEncoding() const;


	/**
	 * @return the instruction that tells us what to render in the display.
	 */
	std::int8_t Instruction() const;


	/**
	 * The data area, which is a buffer that is 16 bytes in length. Used by
	 * instructions.
	 *
	 * @return a pointer to the data element.
	 */	
	const std::int8_t* Data() const;


	/**
	 * Increment the packet to the next packet in the buffer.
	 *
	 * @return a reference to the next packet.
	 */
	Packet& operator++();

	private:
		PacketPrivate* d_ptr;
};


}

