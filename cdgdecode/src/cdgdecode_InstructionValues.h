#pragma once

namespace cdgdecode
{

enum 
{
	// "The following code should set the screen to a particular color."
	MemoryPreset = 1,

	// "Set the border of the screen to a particular color."
	BorderPreset = 2,

	// "Load a 12 x 6, 2 color tile and display it normally."
	TileBlock = 6,

	// "Scroll the image, filling in the new area with a color."
	ScrollPreset = 20,
	
	// "Scroll the image rotating the bits back around."
	ScrollCopy = 24,

	// "Define a specific color as being transparent."
	DefineTransparentColor = 28,

	// "Load in the lower 8 entries of the color table."
	LoadColorTableLow = 30,

	// "Load the upper 8 entries of the color table."
	LoadColorTableHigh = 31,

	// "Load a 12 x 6, color tile and display it using the XOR method."
	TileBlockXOR = 38,

	MaximumNumberOfCommands
};

}


