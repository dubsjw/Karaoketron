#pragma once

#include <type_traits>

namespace cdgdecode
{

template <class T>
struct PodChecker
{
	static_assert( std::is_pod<T>::value, "Input type requires pod type" );
};

}
