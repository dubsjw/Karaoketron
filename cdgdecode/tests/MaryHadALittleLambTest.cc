#include <catch.hpp>
#include <fstream>


const char* MaryHadALittleLambFile = "/tmp/MaryHadALittleLamb.cdg";


SCENARIO( "mary had a little lamb whose fleece was white as snow" )
{
	GIVEN("everywhere that mary went")
	{

		std::ifstream in;
		in.open(MaryHadALittleLambFile, std::ios::in);
		

	}

}
