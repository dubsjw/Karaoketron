
#include "src/cdgdecode_Color.h"

namespace cdgdecode
{

struct ColorPrivate
{
	ColorPrivate(int r, int g, int b)
	: m_r(r)
	, m_g(g)
	, m_b(b)
	{
	}

 
	int m_r;
	int m_g;
	int m_b;
};

Color::Color()
: d_ptr(new ColorPrivate(0, 0, 0))
{
}


Color::Color(int r, int g, int b)
: d_ptr(new ColorPrivate(r, g, b))
{
}


Color::Color(Color const& c)
: d_ptr(new ColorPrivate(*c.d_ptr))
{
}


Color& Color::operator=(Color c)
{
	swap(c);
	return *this;
}


Color::~Color()
{
	delete d_ptr;
}


void Color::swap(Color& c)
{
	std::swap(c.d_ptr, d_ptr);
}



int Color::Red() const
{
	return d_ptr->m_r;
}


int Color::Green() const
{
	return d_ptr->m_g;
}


int Color::Blue() const
{
	return d_ptr->m_b;
}


void Color::SetRed(int r)
{
	d_ptr->m_r = r;
}


void Color::SetGreen(int g)
{
	d_ptr->m_g = g;
}


void Color::SetBlue(int b)
{
	d_ptr->m_b = b;
}


}

