#include "src/cdgdecode_ColorTable.h"
#include <vector>

namespace cdgdecode
{


struct ColorTablePrivate
{
	std::vector<Color> m_colors;

	ColorTablePrivate()
	{
		m_colors.resize(16);
	}
};


ColorTable::ColorTable()
: d_ptr(new ColorTablePrivate())
{
}


ColorTable::~ColorTable()
{
	delete d_ptr;
}


ColorTable::ColorTable(ColorTable const& ct)
: d_ptr(new ColorTablePrivate(*ct.d_ptr))
{
}


ColorTable& ColorTable::operator=(ColorTable ct)
{
	swap(ct);
	return *this;
}


void ColorTable::swap(ColorTable ct)
{
	std::swap(ct.d_ptr, d_ptr);
}


Color& ColorTable::operator[](std::uint8_t index)
{
	if (index >= 16)
	{
		throw std::runtime_error("ColorTable index out of range");
	}

	return d_ptr->m_colors[index];
}


Color const& ColorTable::operator[](std::uint8_t index) const
{
	if (index >= 16)
	{
		throw std::runtime_error("ColorTable index out of range");
	}

	return d_ptr->m_colors[index];
}

}
