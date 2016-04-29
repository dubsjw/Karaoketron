#include "src/cdgdecode_Packet.h"
#include <catch.hpp>

using namespace cdgdecode;

TEST_CASE( "make sure the size of channel decoder is correct", "[ChannelDecoder]")
{
	REQUIRE(sizeof(ChannelDecoder) == 1);
}

TEST_CASE( "channel decoding test -- 1", "[ChannelDecoder]")
{
	ChannelDecoder d;	
	d.data = 0;	

	REQUIRE(d.channel.W == 0);
	REQUIRE(d.channel.V == 0);
	REQUIRE(d.channel.U == 0);
	REQUIRE(d.channel.T == 0);
	REQUIRE(d.channel.S == 0);
	REQUIRE(d.channel.R == 0);
	REQUIRE(d.channel.Q == 0);
	REQUIRE(d.channel.P == 0);

	d.data = 1;
	REQUIRE(d.channel.W == 1);
	REQUIRE(d.channel.V == 0);
	REQUIRE(d.channel.U == 0);
	REQUIRE(d.channel.T == 0);
	REQUIRE(d.channel.S == 0);
	REQUIRE(d.channel.R == 0);
	REQUIRE(d.channel.Q == 0);
	REQUIRE(d.channel.P == 0);


}


TEST_CASE( "channel decoding test -- 2", "[ChannelDecoder]")
{
	ChannelDecoder d;	
	d.data = 2;	

	REQUIRE(d.channel.W == 0);
	REQUIRE(d.channel.V == 1);
	REQUIRE(d.channel.U == 0);
	REQUIRE(d.channel.T == 0);
	REQUIRE(d.channel.S == 0);
	REQUIRE(d.channel.R == 0);
	REQUIRE(d.channel.Q == 0);
	REQUIRE(d.channel.P == 0);
}


TEST_CASE( "channel decoding test -- 3", "[ChannelDecoder]")
{
	ChannelDecoder d;	
	d.data = 3;	

	REQUIRE(d.channel.W == 1);
	REQUIRE(d.channel.V == 1);
	REQUIRE(d.channel.U == 0);
	REQUIRE(d.channel.T == 0);
	REQUIRE(d.channel.S == 0);
	REQUIRE(d.channel.R == 0);
	REQUIRE(d.channel.Q == 0);
	REQUIRE(d.channel.P == 0);
}

