#pragma once

#include <cdgdecode/Globals.h>
#include <cstdint>
#include <memory>

namespace cdgdecode
{

struct CDGBufferPrivate;

class CDGDECODE_EXPORT CDGBuffer
{
	public:
		CDGBuffer();
		~CDGBuffer();
		CDGBuffer(CDGBuffer const& b);
		CDGBuffer& operator=(CDGBuffer b);
		void swap(CDGBuffer& b);

		void Open(const char* filename);
		bool IsOpen() const;
		std::uint32_t SizeOfBuffer() const;
		std::uint8_t* GetBufferPtr(std::uint32_t index) const;

	private:
		std::unique_ptr<CDGBufferPrivate> d_ptr;
};

}


