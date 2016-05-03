#pragma once

namespace cdgdecode
{

namespace screen
{

	enum
	{
		Width = 300,
		
		Height = 216,
		
		BorderWidth = 6,
	
		BorderHeight = 12,

		ViewX1 = BorderWidth,

		ViewY1 = BorderHeight,

		ViewX2 = (Width - BorderWidth),

		ViewY2 = (Height - BorderHeight),

		TileWidth = 12,
		
		TileHeight = 6,

		NumberOfHorizontalTiles = (ViewX2 - ViewX1) / TileWidth,

		NumberOfVerticalTiles = (ViewY2 - ViewY1) / TileHeight

	};
}	

}

