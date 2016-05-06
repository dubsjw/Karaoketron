#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>
#include <cdgdecode/Screen.h>
#include <cdgdecode/Tile.h>
#include "src/cdgdecode_BitMask.h"
#include "src/TileFromData.h"

// std dependencies
#include <cstdint>
#include <iostream>

namespace cdgdecode
{

/**
 * This function will handle tile block drawing.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
template <typename EngineType>
inline void HandleTileBlockPreset(EngineType& engine, Packet const& packet)
{
	TileBlockData const* tileBlockData =
	    reinterpret_cast<TileBlockData const*>(packet.Data());	

	std::int8_t row = tileBlockData->row & 0x1f;
	std::int8_t column = tileBlockData->column & 0x3f;

	Tile tile;
	TileFromData(packet, tile);
	engine.DrawTile( row, column, tile );	
}

}


