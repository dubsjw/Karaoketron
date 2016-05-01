#include "src/CDGBuffer.h"
#include "src/ReadFile.h"
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace cdgdecode
{

struct CDGBufferPrivate
{
	std::shared_ptr<std::vector<std::uint8_t> > m_buffer;
};


CDGBuffer::CDGBuffer()
: d_ptr(new CDGBufferPrivate())
{
}


CDGBuffer::~CDGBuffer()
{
}


CDGBuffer::CDGBuffer(CDGBuffer const& b)
: d_ptr(new CDGBufferPrivate(*b.d_ptr))
{
}


CDGBuffer& CDGBuffer::operator=(CDGBuffer b)
{
	swap(b);
	return *this;
}


void CDGBuffer::swap(CDGBuffer& b)
{
	std::swap(b.d_ptr, d_ptr);
}


void CDGBuffer::Open(const char* filename)
{
	d_ptr->m_buffer = std::make_shared<std::vector<std::uint8_t> >();
	ReadFile( filename, *d_ptr->m_buffer );
}


std::uint8_t* CDGBuffer::GetBufferPtr(std::uint32_t index) const
{
	if (d_ptr->m_buffer.get() == nullptr)
	{
		throw std::runtime_error("Internal buffer has not been loaded");
	}

	if (d_ptr->m_buffer->size() <= index)
	{
		throw std::runtime_error("Invalid index provided to GetBufferPtr");
	}
	
	return &(d_ptr->m_buffer.get()->operator[](index));	
}


bool CDGBuffer::IsOpen() const
{
	return (d_ptr->m_buffer.get() != nullptr) && (d_ptr->m_buffer->size() > 0);
}


std::uint32_t CDGBuffer::SizeOfBuffer() const
{
	std::uint32_t out = 0;
	if (d_ptr->m_buffer.get() != nullptr)
	{
		out = static_cast<std::uint32_t>(d_ptr->m_buffer->size());
	}
	return out; 
}

}


