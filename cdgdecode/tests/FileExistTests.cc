#include "src/FileExists.h"
#include <catch.hpp>


TEST_CASE("test if non-existing file exists")
{
	bool exists = cdgdecode::FileExists("blahblahblahFile.txt");
	REQUIRE(exists == false);
}


TEST_CASE("test to see if the binary file exists")
{
	#if defined __linux__
	bool exists = cdgdecode::FileExists("CDGDecodeTests");
	#else

	#endif
	REQUIRE(exists == true);
}
