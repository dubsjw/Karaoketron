#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>
#include "src/cdgdecode_BitMask.h"

// std dependencies
#include <cstdint>

namespace cdgdecode
{

/**
 * The following is the encoding of the border preset data. Only the lower 
 * four bits of the color are used.
 */
struct BorderPresetData
{
	std::int8_t color;
	std::int8_t filler[15];
};


/**
 * Use the following function as the entry point to handling a 
 * border preset instruction. 
 *
 * @param EngineType 1) Must be an object type.
 *                   2) Must have a ClearBorder method that takes a color identifier.
 *
 * @param engine The Engine object that could display something or is a mock
 *               that could be tested.
 * @param packet The packet that is decoded to provide border color.
 */
template <typename EngineType>
inline void HandleBorderPreset(EngineType& engine, Packet const& packet)
{
	// First go ahead and apply the reinterpret cast so that we can 
	// get at the data in a civilized way.
	BorderPresetData const* borderPresetData = 
	    reinterpret_cast<BorderPresetData const*>(packet.Data());

	// Load up the mask with the data.
	BitMask bm;

	// Obtain the color information.
	bm.data = borderPresetData->color;	
	auto color = mpm.mask.lower;	
	
	// Clear the screen with the color given.
	engine.ClearBorder( color );
}

}

