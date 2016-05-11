#pragma once

// cdgdecode dependencies
#include <cdgdecode/Color.h>
#include <cdgdecode/Globals.h>

// std dependencies
#include <cstdint>
#include <memory>

namespace cdgdecode
{
struct ColorTablePrivate;

struct CDGDECODE_EXPORT ColorTable
{
	ColorTable();
	~ColorTable();
	ColorTable(ColorTable const& ct);
	ColorTable& operator=(ColorTable ct);
	void swap(ColorTable ct);

	Color& operator[](std::uint8_t index);
	Color const& operator[](std::uint8_t index) const;

	private:
		ColorTablePrivate* d_ptr;	
};

}
