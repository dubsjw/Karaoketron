#include "src/cdgdecode_Tile.h"
#include "src/cdgdecode_Screen.h"
#include <vector>

namespace cdgdecode
{

struct TileRowPrivate
{
	std::vector<std::int8_t>* const m_row;

	TileRowPrivate(std::vector<std::int8_t>* const in)
	: m_row(in)
	{
	}
};

TileRow::TileRow(TileRowPrivate* d)
: d_ptr(d)
{
}


TileRow::~TileRow()
{
	delete d_ptr;
}


TileRow::TileRow(TileRow const& tr)
: d_ptr(new TileRowPrivate(*tr.d_ptr))
{
}


TileRow& TileRow::operator=(TileRow tileRow)
{
	swap(tileRow);
	return *this;
}


std::int8_t& TileRow::operator[](std::int8_t y)
{
	if (y >= screen::TileHeight)
	{
		throw std::runtime_error("Invalid input index to tile row");
	}
	return d_ptr->m_row->at(y);
}


std::int8_t const& TileRow::operator[](std::int8_t y) const
{
	if (y >= screen::TileHeight)
	{
		throw std::runtime_error("Invalid input index to tile row");
	}
	return d_ptr->m_row->at(y);
}


void TileRow::swap(TileRow& tr)
{
	std::swap(tr.d_ptr, d_ptr);
}


struct TilePrivate
{
	std::vector<std::vector<std::int8_t> > m_pixels;
};


Tile::Tile()
: d_ptr(new TilePrivate())
{
	d_ptr->m_pixels.resize(screen::TileWidth);
	for(int i=0; i<screen::TileWidth; ++i)
	{
		d_ptr->m_pixels[i].resize(screen::TileHeight);
	}
}


Tile::~Tile()
{
	delete d_ptr;
}


Tile::Tile(Tile const& t)
: d_ptr(new TilePrivate(*t.d_ptr))
{
}


Tile& Tile::operator=(Tile t)
{
	swap(t);
	return *this;
}


void Tile::swap(Tile& t)
{
	std::swap(t.d_ptr, d_ptr);
}


TileRow Tile::operator[](std::int8_t x)
{
	auto constTile = const_cast<const Tile*>(this);
	return constTile->operator[](x);
}


TileRow const Tile::operator[](std::int8_t x) const
{
	if (x >= screen::TileWidth)
	{
		throw std::runtime_error("Invalid dimension given to x");
	} 	

	return TileRow(new TileRowPrivate(& (d_ptr->m_pixels[x]) ) );
}

}


