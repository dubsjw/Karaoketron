#pragma once

#if defined _WIN32 || defined _WIN64

	#if defined CDGDECODE_SHARED_LIBRARY

		#define CDGDECODE_EXPORT __declspec(dllexport)

	#elif defined CDGDECODE_USE_LIBRARY

		#define CDGDECODE_EXPORT __declspec(dllimport)

	#else

		#define CDGDECODE_EXPORT 

	#endif
#else

	#define CDGDECODE_EXPORT 

#endif

