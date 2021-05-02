#pragma once

#ifdef HM_PLATFORM_WINDOWS
	#ifdef HM_BUILD_DLL
		#define HUMMER_API __declspec(dllexport)
	#else
		#define HUMMER_API __declspec(dllimport)
	#endif
#else
	#error Hummer only support Windows!
#endif

#ifdef HM_ENABLE_ASSERTS
	#define HM_ASSERT(x, ...) { if(!(x)) {HM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HM_CORE_ASSERT(x, ...) { if(!(x)) {HM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HM_ASSSERT(x, ...)
	#define HM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

