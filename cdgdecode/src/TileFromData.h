#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>

namespace cdgdecode
{

enum { NumberOfTilePixels = 12 };

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
	std::int8_t tilePixels[NumberOfTilePixels];
};


/**
 * This function will handle tile block drawing.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
inline void TileFromData(Packet const& packet, Tile& tile)
{

	TileBlockData const* tileBlockData =
	    reinterpret_cast<TileBlockData const*>(packet.Data());	

	std::int8_t color0 = tileBlockData->color0 & 0x0f;
	std::int8_t color1 = tileBlockData->color1 & 0x0f;

	int x = 0;
	int y = 0;

	for(int i=0; i<NumberOfTilePixels; ++i)
	{
		std::int8_t pixeldata = (tileBlockData->tilePixels[i] & 0x3f);
		
		for(int j=0; j<6; ++j)
		{
			tile[x][y] = ( (pixeldata & 64) != 0 ) ? color1 : color0;

			++x;
			if (x >= screen::TileWidth)
			{
				x = 0;
				++y;
			}
			pixeldata = (pixeldata << 1);
		}
	}		
}



}
