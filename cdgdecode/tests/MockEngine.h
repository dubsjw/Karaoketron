#pragma once

#include <cdgdecode/ColorTable.h>
#include <cdgdecode/Screen.h>
#include <cdgdecode/Tile.h>
#include <cstdint>
#include <cstdlib>
#include <vector>

namespace cdgdecode
{

struct MockEngine
{
	//! Keep track of all times clear was called.
	std::vector<std::int8_t> m_clearRecord;

	//! The screen.
	std::vector<std::vector<std::int8_t> > m_screen;

	//! The color table.
	ColorTable m_colorTable;

	MockEngine()
	{
		m_screen.resize(screen::Width);
		for(int i=0; i<screen::Width; ++i)
		{
			// Initialize purposefully with garbage.
			m_screen[i].resize(screen::Height);
			for(int j=0; j<screen::Height; ++j)
			{
				m_screen[i][j] = static_cast<std::int8_t>(rand() % 100);
			}
		}
	}

	/**
	 * The following method is required by the MemoryPreset 
	 * instruction.
	 */
	void Clear(std::int8_t color)
	{
		for(int i= screen::ViewX1; i<screen::ViewX2; ++i)
		{
			for(int j=screen::ViewY1; j<screen::ViewY2; ++j)
			{
				m_screen[i][j] = color;	
			}
		}
	}


	void ClearBorder(std::int8_t color)
	{

	}


	void DrawTile( std::int8_t row, std::int8_t column
	             , Tile const& tile )
	{

	}


	void DrawXORTile( std::int8_t row, std::int8_t column
	                , Tile const& tile )
	{

	}

	ColorTable& Palette()
	{
		return m_colorTable;
	}
};



}

