#pragma once

#if defined _WIN32 || defined _WIN64

	#if defined CDGQT5_SHARED_LIBRARY

		#define CDGQT5_EXPORT __declspec(dllexport)

	#elif defined CDGQT5_USE_LIBRARY

		#define CDGQT5_EXPORT __declspec(dllimport)

	#else

		#define CDGQT5_EXPORT 

	#endif
#else

	#define CDGQT5_EXPORT 

#endif

