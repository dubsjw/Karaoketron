#pragma once

// std dependencies
#include <memory>

namespace cdgdecode
{

struct ColorPrivate;

struct Color
{
	Color();
	Color(int r, int g, int b);
	Color(Color const& c);
	Color& operator=(Color c);
	~Color();
	void swap(Color& c);

	int Red() const;
	int Green() const;
	int Blue() const;

	void SetRed(int r);
	void SetGreen(int g);
	void SetBlue(int b);

	private:
		std::unique_ptr<ColorPrivate> d_ptr;
};


}
