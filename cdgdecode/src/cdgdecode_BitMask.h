#pragma once

#include <cstdint>

namespace cdgdecode
{

struct SplitMask
{
	unsigned char upper : 4;
	unsigned char lower : 4;
};

union BitMask
{
	std::int8_t data;
	SplitMask upperLower;
};

};

