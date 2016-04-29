#include "src/cdgdecode_Decode.h"
#include "src/cdgdecode_Packet.h"
#include "src/ReadFile.h"
#include <cstdint>
#include <vector>


namespace cdgdecode
{

void Read(const char* filename)
{
	std::vector<std::uint8_t> data;	

	// Read in the file into a data buffer. This will make 
	// interpreting much quicker.
	ReadFile(filename, data);


	// Attempt to read in a packet.
	
}

}

