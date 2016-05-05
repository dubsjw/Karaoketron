#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>
#include <cdgdecode/Screen.h>
#include <cdgdecode/Tile.h>
#include "src/cdgdecode_BitMask.h"

// std dependencies
#include <cstdint>
#include <iostream>


namespace cdgdecode
{


/**
 * This function will handle loading a palette in.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
template <typename EngineType>
inline void HandleLoadHighPalette(EngineType& engine, Packet const& packet)
{
}


/**
 * This function will handle loading a palette in.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
template <typename EngineType>
inline void HandleLoadLowPalette(EngineType& engine, Packet const& packet)
{
}



}

