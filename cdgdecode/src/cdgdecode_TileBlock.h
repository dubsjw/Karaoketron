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

	TileBlockChannel tbc;

	tbc.data = tileBlockData->row;
	auto row = tbc.l5.lower5;

	tbc.data = tileBlockData->column;
	auto column = tbc.l6.lower6;


	Tile tile;
	TileFromData(packet, tile);
	engine.DrawTile( row, column, tile );	
}

}


