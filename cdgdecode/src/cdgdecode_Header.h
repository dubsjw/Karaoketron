#pragma once

// std dependencies
#include <cstdint>
#include <memory>

namespace cdgdecode
{

struct HeaderPrivate;

struct Header
{
	Header();
	Header( Header const& header);
	Header& operator=(Header header);
	~Header();
	void swap(Header& header);

	private:
		std::unique_ptr<HeaderPrivate> d_ptr;
};

}


