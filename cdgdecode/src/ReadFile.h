#pragma once

// std dependencies
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>


inline void ReadFile( const char* filename, std::vector<std::uint8_t>& contents )
{
	std::ifstream f;
	f.open(filename, std::ios::in | std::ios::binary);
	f.seekg(0, std::ios::end);

	auto sizeOfFile = f.tellg();
	f.seekg(0, std::ios::beg);
	
	contents.reserve( sizeOfFile );
	contents.assign( std::istreambuf_iterator<char>(f) 
	               , std::istreambuf_iterator<char>());

	f.close();
}

