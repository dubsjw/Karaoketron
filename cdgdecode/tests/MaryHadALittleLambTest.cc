#include "src/cdgdecode_InstructionValues.h"
#include "src/cdgdecode_Packet.h"
#include "src/CDGBuffer.h"
#include "src/FileExists.h"
#include "src/ReadFile.h"
#include <cdgdecode/PacketProcessor.h>
#include <catch.hpp>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>


const char* MaryHadALittleLambFile = "/tmp/MaryHadALittleLamb.cdg";

enum 
{
	StartOfPackets = 16 * 6 

};

SCENARIO( "mary had a little lamb whose fleece was white as snow" )
{
	GIVEN("everywhere that mary went")
	{
		if (false == cdgdecode::FileExists(MaryHadALittleLambFile))
		{
			return;
		}
		
		
		// Opening MaryHadALittleLamb.
		cdgdecode::CDGBuffer buffer;
		buffer.Open(MaryHadALittleLambFile);

		// First require that the buffer read in is greater than 0.
		// Something is better than nothing.
		REQUIRE(buffer.IsOpen() == true);

		// Secondly make sure that we can actually attempt to 
		// decode that first packet.
		REQUIRE(buffer.SizeOfBuffer() > (StartOfPackets + sizeof(cdgdecode::SubCode)));

		WHEN( "creating a packet" )
		{
			cdgdecode::Packet packet(buffer, StartOfPackets);

			THEN( "the raw command should just be a 9 for now")
			{
				auto cmd = packet.RawCommand();
				REQUIRE(cmd == 9);
			}

			THEN( "if it was a 9, then it is a legal cdg packet")
			{
				REQUIRE(packet.HasCDGEncoding() == true);
			}

			THEN( "grab the instruction" )
			{
				REQUIRE(packet.Instruction() == cdgdecode::MemoryPreset);
			}
		}


		WHEN( "creating and incrementing a packet")
		{
			cdgdecode::Packet packet(buffer, StartOfPackets);
			int packetIndex = 0;

			// Go to the next packet.
			while(packet.HasCDGEncoding() && packet.Instruction() <= 2)
			{
				++packet;
				packetIndex += 1;
			}
			std::cout << "Is CDG Encoded : " << packet.HasCDGEncoding() << std::endl;
			std::cout << "Instruction    : " << static_cast<std::int32_t>(packet.Instruction()) << std::endl;
			std::cout << "PacketIndex    : " << packetIndex << std::endl;
		}
	}



}
