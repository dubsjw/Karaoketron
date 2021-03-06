#include "src/cdgdecode_Color.h"
#include "src/cdgdecode_LoadPalette.h"
#include <catch.hpp>
#include <iterator>
#include <vector>

using namespace cdgdecode;

TEST_CASE( "testing out encoding/decoding color 0")
{
	ColorEncodingHighByte high;
	ColorEncodingLowByte low;

	high.red = 0;
	high.green = 0;
	low.green = 0;
	low.blue = 0;

	auto c = ExtractColorData( high, low );	
	REQUIRE(c.Red() == 0);
	REQUIRE(c.Green() == 0);
	REQUIRE(c.Blue() == 0);
}


TEST_CASE( "testing out encoding/decoding blue" )
{
	ColorEncodingHighByte high;
	ColorEncodingLowByte low;

	high.red = 0;
	high.green = 0;
	low.green = 0;
	low.blue = 10;

	auto c = ExtractColorData( high, low );	
	REQUIRE(c.Red() == 0);
	REQUIRE(c.Green() == 0);
	REQUIRE(c.Blue() == 10);
}


TEST_CASE( "testing out encoding/decoding red" )
{
	ColorEncodingHighByte high;
	ColorEncodingLowByte low;

	high.red = 10;
	high.green = 0;
	low.green = 0;
	low.blue = 0;

	auto c = ExtractColorData( high, low );	
	REQUIRE(c.Red() == 10);
	REQUIRE(c.Green() == 0);
	REQUIRE(c.Blue() == 0);
}
