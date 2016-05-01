#include "src/cdgdecode_Header.h"

namespace cdgdecode
{

struct HeaderPrivate
{
	
};


Header::Header()
: d_ptr(new HeaderPrivate())
{
}


Header::Header( Header const& header)
: d_ptr(new HeaderPrivate(*header.d_ptr))
{
}


Header& Header::operator=(Header header)
{
	swap(header);
	return *this;
}


Header::~Header()
{
}


void Header::swap(Header& header)
{
	std::swap(header.d_ptr, d_ptr);
}

}


