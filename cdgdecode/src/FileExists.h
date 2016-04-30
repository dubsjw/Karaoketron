#pragma once

#if defined __linux__

	#include <sys/stat.h>
	#include <unistd.h>

	inline bool is_file_exist(const char* filename) 
	{
		struct stat buffer;   
		return (stat (filename, &buffer) == 0); 
	}

#else
	#include <ifstream>

	inline bool is_file_exist(const char* filename)
	{
		std::ifstream infile(filename);
		return infile.good();	
	}

#endif

namespace cdgdecode
{


inline bool FileExists(const char* filename)
{
	return is_file_exist(filename);	
}


}

