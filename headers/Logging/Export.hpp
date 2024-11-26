#pragma once

#ifndef LOGGING_API
	#ifdef _WIN32
		#ifdef BUILD_LOGGING_LIB
			#define LOGGING_API __declspec(dllexport)
		#elif USE_LOGGING_LIB
			#define LOGGING_API __declspec(dllimport)
		#else
			#define LOGGING_API
		#endif
	#else
		#if defined(BUILD_LOGGING_LIB) || defined(USE_LOGGING_LIB)
			#define LOGGING_API __attribute__((__visibility__("default")))
		#else
			#define LOGGING_API
		#endif
	#endif
#endif