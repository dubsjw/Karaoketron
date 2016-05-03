#include "src/cdgdecode_Packet.h"
#include "src/CDGBuffer.h"
#include <iostream>

namespace cdgdecode
{

struct PacketPrivate
{
	PacketPrivate( CDGBuffer const& buffer, std::uint32_t index)
	: m_buffer(buffer)
	, m_index(index)
	, m_subCode(nullptr)
	{
		Reload(index);
	}

	CDGBuffer m_buffer;
	std::uint32_t m_index;
	SubCode* m_subCode;


	void Reload(std::uint32_t index)
	{
		m_index = index;
		m_subCode = reinterpret_cast<SubCode*>(m_buffer.GetBufferPtr(index));	
	}
};


Packet::Packet(CDGBuffer const& buffer, std::uint32_t index)
: d_ptr(new PacketPrivate(buffer, index))
{
}


Packet::~Packet()
{
}


Packet::Packet(Packet const& packet)
: d_ptr(new PacketPrivate(*packet.d_ptr))
{
}


Packet& Packet::operator=(Packet packet)
{
	swap(packet);
	return *this;
}


void Packet::swap(Packet& packet)
{
	std::swap(packet.d_ptr, d_ptr);
}


void Packet::ReloadAtPosition(std::uint32_t index)
{
	d_ptr->Reload(index);	
}


std::int8_t Packet::RawCommand() const
{
	return d_ptr->m_subCode->command;
}


bool Packet::HasCDGEncoding() const
{
	// Create a ChannelDecoder, a union that make checking  a
	// simple comparison operation.
	ChannelDecoder decoder;		

	// Assign the data to the current command.
	decoder.data = d_ptr->m_subCode->command;

	// Check the mask, if the value is 9 then we have CDG data.
	return (decoder.mask.payload == 9);
}


std::int8_t Packet::Instruction() const
{
	ChannelDecoder decoder;
	decoder.data = d_ptr->m_subCode->instruction;
	return (decoder.mask.payload);
}


const std::int8_t* Packet::Data() const
{
	return &(d_ptr->m_subCode->data[0]);
}


Packet& Packet::operator++()
{
	auto nextIndex = d_ptr->m_index + sizeof(SubCode);	
	d_ptr->Reload(nextIndex);
	return *this;
}


}

