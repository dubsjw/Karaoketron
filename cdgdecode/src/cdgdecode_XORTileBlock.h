#pragma once

// cdgdecode dependencies
#include "src/cdgdecode_TileBlock.h"
#include "src/TileFromData.h"

namespace cdgdecode
{

/**
 * This function will handle tile block drawing.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
template <typename EngineType>
inline void HandleXORTileBlockPreset(EngineType& engine, Packet const& packet)
{

	Tile tile;
	TileFromData(packet, tile);
	engine.DrawXORTile( row, column, tile );	
}

}


