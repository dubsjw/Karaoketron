#pragma once

// cdgdecode dependencies
#include <cdgdecode/Globals.h>

// std dependencies
#include <cstdint>
#include <memory>

namespace cdgdecode
{

struct HeaderPrivate;

struct CDGDECODE_EXPORT Header
{
	Header();
	Header( Header const& header);
	Header& operator=(Header header);
	~Header();
	void swap(Header& header);

	private:
		HeaderPrivate* d_ptr;
};

}


