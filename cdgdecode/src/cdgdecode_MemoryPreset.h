#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>

// std dependencies
#include <cstdint>

namespace cdgdecode
{

struct Top4Mask
{
	unsigned char upper : 4;
	unsigned char lower : 4;
};


union MemoryPresetMask
{
	Top4Mask mask;	
	std::int8_t data;
};


/**
 * The following is the encoding of the memory preset data.
 */
struct MemoryPresetData
{
	std::int8_t color;
	std::int8_t repeat;
	std::int8_t filler[14];
};


/**
 * Use the following function as the entry point to handling a 
 * memory preset instruction. 
 *
 * @param EngineType 1) Must be an object type.
 *                   2) Must have a Clear method that takes a color identifier.
 *
 * @param engine The Engine object that could display something or is a mock
 *               that could be tested.
 * @param packet The packet that is decoded to provide background color.
 */
template <typename EngineType>
inline void HandleMemoryPreset(EngineType& engine, Packet const& packet)
{
	// First go ahead and apply the reinterpret cast so that we can 
	// get at the data in a civilized way.
	MemoryPresetData const* memoryPresetData = 
	    reinterpret_cast<MemoryPresetData const*>(packet.Data());

	// Load up the mask with the data.
	MemoryPresetMask mpm;

	// Obtain the color information.
	mpm.data = memoryPresetData->color;	
	auto color = mpm.mask.lower;	
	
	// Obtain the repeat information.
	mpm.data = memoryPresetData->repeat;
	auto repeat = mpm.mask.lower;

	/**
	 * According to docs, if these memory preset commands happen in 
	 * bunches then the repeat count is used to number them. Essentially
	 * the documentation states we can ignore the command if repeat 
	 * is not equal to 0.
	 */

	if (repeat == 0)
	{
		// Clear the screen with the color given.
		engine.Clear( color );
	}
}

}

