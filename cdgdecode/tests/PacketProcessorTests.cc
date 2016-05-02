#include <cdgdecode/PacketProcessor.h>
#include <catch.hpp>

struct MockEngine
{

};

using namespace cdgdecode;

SCENARIO("test out packet processor initialization", "[PacketProcessor]")
{
	GIVEN( "a packet processor" )
	{
		MockEngine engine;
		PacketProcessor<MockEngine> pp(engine);

		REQUIRE(pp.m_processors.size() > 38);
	}
}
