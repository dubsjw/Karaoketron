#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>

namespace cdgdecode
{


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
inline void TileFromData(Packet const& packet, Tile& tile)
{

	TileBlockData const* tileBlockData =
	    reinterpret_cast<TileBlockData const*>(packet.Data());	

	TileBlockChannel tbc;
	tbc.data = tileBlockData->color0;
	auto color0 = tbc.l4.lower4;

	tbc.data = tileBlockData->color1;
	auto color1 = tbc.l4.lower4;
	int x = 0;
	int y = 0;

	for(int i=0; i<12; ++i)
	{
		tbc.data = tileBlockData->tilePixels[i];	
		
		tile[x][y] = tbc.drawing.bit0 ? color1 : color0;	
		tile[x+1][y] = tbc.drawing.bit1 ? color1 : color0;	
		tile[x+2][y] = tbc.drawing.bit2 ? color1 : color0;	
		tile[x+3][y] = tbc.drawing.bit3 ? color1 : color0;	
		tile[x+4][y] = tbc.drawing.bit4 ? color1 : color0;	
		tile[x+5][y] = tbc.drawing.bit5 ? color1 : color0;	

		x = x + 6;
		if (x >= screen::TileWidth)
		{
			x = 0;
			++y;
		} 
	}		
}



}
