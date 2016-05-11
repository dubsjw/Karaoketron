#pragma once

//CDGDecode Dependencies
#include <cdgdecode/Globals.h>

// std dependencies
#include <cstdint>
#include <memory>

namespace cdgdecode
{

struct TileRowPrivate;
struct CDGDECODE_EXPORT TileRow
{
	TileRow(TileRowPrivate* d);
	~TileRow();
	TileRow(TileRow const&);
	TileRow& operator=(TileRow);
	void swap(TileRow& tr);


	std::int8_t& operator[](std::int8_t y);
	std::int8_t const& operator[](std::int8_t y) const;

	private:
		TileRowPrivate* d_ptr;
};

struct TilePrivate;
struct CDGDECODE_EXPORT Tile
{
	Tile();
	~Tile();
	Tile(Tile const& t);
	Tile& operator=(Tile t);
	void swap(Tile& t);


	TileRow operator[](std::int8_t x);
	TileRow const operator[](std::int8_t x) const;


	private:
		TilePrivate* d_ptr;
};

}


