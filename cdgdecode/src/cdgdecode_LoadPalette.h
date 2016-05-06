#pragma once

// cdgdecode dependencies
#include <cdgdecode/Color.h>
#include <cdgdecode/ColorTable.h>
#include <cdgdecode/Packet.h>
#include <cdgdecode/Screen.h>
#include <cdgdecode/Tile.h>
#include "src/cdgdecode_BitMask.h"
#include "src/ChannelEncoding.h"

// std dependencies
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <vector>


namespace cdgdecode
{


struct ColorData
{
	ColorEncodingHighByte high0;
	ColorEncodingLowByte low0;

	ColorEncodingHighByte high1;
	ColorEncodingLowByte low1;

	ColorEncodingHighByte high2;
	ColorEncodingLowByte low2;

	ColorEncodingHighByte high3;
	ColorEncodingLowByte low3;

	ColorEncodingHighByte high4;
	ColorEncodingLowByte low4;

	ColorEncodingHighByte high5;
	ColorEncodingLowByte low5;

	ColorEncodingHighByte high6;
	ColorEncodingLowByte low6;

	ColorEncodingHighByte high7;
	ColorEncodingLowByte low7;
};


inline Color ExtractColorData( ColorEncodingHighByte& high
                             , ColorEncodingLowByte& low )
{
	auto red = high.red;	
	auto green = (high.green << 2) | low0.green;
	auto blue = low0.blue; 

	return Color(red, green, blue);
}


template <typename Iterator>
void ExtractColorData(ColorData const& cd, Iterator iter )
{
	*iter = ExtractColorData( cd.high0, cd.low0 );
	++iter;
}


/**
 * This function will handle loading a palette in.
 *
 * @param engine The engine to write a tile to.
 * @param packet The packet to decode.
 */
template <typename EngineType>
inline void HandleLoadHighPalette(EngineType& engine, Packet const& packet)
{
	// Reinterpret cast the color data.
	ColorData const* colorData = reinterpret_cast<ColorData const*>(packet.Data());

	// Grab a reference to the palette. 
	ColorTable& colorTable = engine.Palette();	
	
	// A collection of colors decoded from the packet.
	std::vector<Color> colors;
	colors.resize(8);

	ExtractColorData( *colorData, colors.begin() );
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
	// Grab a reference to the palette. 
	ColorTable& colorTable = engine.Palette();	

	// A collection of colors decoded from the packet.
	std::vector<Color> colors;
	colors.resize(8);
}



}

