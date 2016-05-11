#pragma once

// cdgdecode dependencies
#include <cdgdecode/Color.h>
#include <cdgdecode/ColorTable.h>
#include <cdgdecode/Packet.h>
#include <cdgdecode/Screen.h>
#include <cdgdecode/Tile.h>
#include "src/cdgdecode_BitMask.h"
#include "src/ChannelEncoding.h"
#include "src/ColorEncoding.h"

// std dependencies
#include <algorithm>
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


template <int Base, typename InType>
int ConvertTo255(InType input)
{
	float f = static_cast<float>(input) / static_cast<float>(Base);
	return static_cast<int>(255.0 * f);
}


inline Color ExtractColorData( ColorEncodingHighByte const& high
                             , ColorEncodingLowByte const& low )
{
	auto red = ConvertTo255<16>(high.red);
	auto green = ConvertTo255<16>((high.green<< 2) | low.green);
	auto blue = ConvertTo255<16>(low.blue);

	return Color(red, green, blue);
}


template <typename Iterator>
void ExtractColorData(ColorData const& cd, Iterator iter )
{
	*iter = ExtractColorData( cd.high0, cd.low0 );
	++iter;

	*iter = ExtractColorData( cd.high1, cd.low1 );
	++iter;

	*iter = ExtractColorData( cd.high2, cd.low2 );
	++iter;

	*iter = ExtractColorData( cd.high3, cd.low3 );
	++iter;

	*iter = ExtractColorData( cd.high4, cd.low4 );
	++iter;

	*iter = ExtractColorData( cd.high5, cd.low5 );
	++iter;

	*iter = ExtractColorData( cd.high6, cd.low6 );
	++iter;

	*iter = ExtractColorData( cd.high7, cd.low7 );
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

	int counter = 8;
	std::for_each( colors.begin(), colors.end(), [&colorTable, &counter](Color const& c)
	{
		colorTable[counter] = c;
		++counter;
	});
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
	// Reinterpret cast the color data.
	ColorData const* colorData = reinterpret_cast<ColorData const*>(packet.Data());

	// Grab a reference to the palette. 
	ColorTable& colorTable = engine.Palette();	

	// A collection of colors decoded from the packet.
	std::vector<Color> colors;
	colors.resize(8);

	ExtractColorData( *colorData, colors.begin() );

	int counter = 0;
	std::for_each( colors.begin(), colors.end(), [&colorTable, &counter](Color const& c)
	{
		colorTable[counter] = c;
		++counter;
	});

}



}

