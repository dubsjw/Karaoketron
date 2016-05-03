#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>
#include "src/cdgdecode_BitMask.h"

// std dependencies
#include <cstdint>

namespace cdgdecode
{

struct Lower4
{
	unsigned char lower4 : 4;
	unsigned char upper4 : 4;
};

struct Lower5
{
	unsigned char lower5 : 5;
	unsigned char lower3 : 3;
};

struct Lower6
{
	unsigned char lower6 : 6;
	unsigned char lower2 : 2;
};


union TileBlockChannel
{
	std::int8_t data;
	Lower4 l4;
	Lower5 l5;
	Lower6 l6;
};


struct TileBlockData
{
	//! The lower four bits are the color that should be used
	//! when drawing bits that are 0.
	std::int8_t color0;           

	//! The lower four bits are the color that should be used 
	//! when drawing bits that are 1.
	std::int8_t color1;

	//! The lower 5 bits are used to designate the row.
	std::int8_t row;

	//! The lower 6 bits are used to designate the column.
	std::int8_t column;

	//! Only the lower 6 bits are used in each value, they designate the
	//! raw drawing value. Each bit signals either use color0 or color1.
	std::int8_t tilePixels[12];
};


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
	tbc.data = tileBlockData->color0;
	auto color0 = tbc.l4.lower4;

	tbc.data = tileBlockData->color1;
	auto color1 = tbc.l4.lower4;

	tbc.data = tileBlockData->row;
	auto row = tbc.l5.lower5;

	tbc.data = tileBlockData->column;
	auto column = tbc.l6.lower6;

	static std::int8_t tile[screen::TileWidth][screen::TileHeight];

	for(int y=0; y<screen::TileHeight; ++y)
	{
		for(int x=0; x<screen::TileWidth; ++x)
		{
			// Initialize the tile data.
		}
	}

	engine.DrawTile( row, column, tile );	
}

}


