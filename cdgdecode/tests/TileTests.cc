#include "src/cdgdecode_Screen.h"
#include "src/cdgdecode_Tile.h"
#include <catch.hpp>

SCENARIO( "creating/accessing tile and its memory", "[Tile]")
{
	GIVEN( "a tile")
	{
		cdgdecode::Tile t1;
		WHEN("setting a  pixel")
		{
			t1[0][0] = 3;
			THEN("the pixel value should be stored")
			{
				REQUIRE(t1[0][0] == 3);
			}	
		}

		WHEN("clearing all pixels")
		{
			for(int x=0; x<cdgdecode::screen::TileWidth; ++x)
				for(int y=0; y<cdgdecode::screen::TileHeight; ++y)
				{
					t1[x][y] = 0;
				}

			THEN( "the pixels should have been blanked")
			{
				for(int x=0; x<cdgdecode::screen::TileWidth; ++x)
					for(int y=0; y<cdgdecode::screen::TileHeight; ++y)
					{
						REQUIRE(t1[x][y] == 0);
					}
			}
		}


		WHEN("clearing and copying pixels")
		{
			for(int x=0; x<cdgdecode::screen::TileWidth; ++x)
				for(int y=0; y<cdgdecode::screen::TileHeight; ++y)
				{
					t1[x][y] = 5;
				}

			cdgdecode::Tile t2(t1);

			THEN( "the pixels should have been blanked")
			{
				for(int x=0; x<cdgdecode::screen::TileWidth; ++x)
					for(int y=0; y<cdgdecode::screen::TileHeight; ++y)
					{
						REQUIRE(t2[x][y] == 5);
					}
			}
		}


	}
}

