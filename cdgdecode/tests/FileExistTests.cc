#include "src/FileExist.h"
#include <catch.hpp>


TEST_CASE("test if non-existing file exists")
{
	bool exists = cdgdecode::FileExists("blahblahblahFile.txt");
	REQUIRES(exists == false);
}
