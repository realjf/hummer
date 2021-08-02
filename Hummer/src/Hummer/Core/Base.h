#pragma once

#include <memory>

#include "Hummer/Core/PlatformDetection.h"

#ifdef HM_DEBUG
#if defined(HM_PLATFORM_WINDOWS)
#define HM_DEBUGBREAK() __debugbreak()
#elif defined(HM_PLATFORM_LINUX)
#include <signal.h>
#define HM_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define HM_ENABLE_ASSERTS
#else
#defineHM_DEBUGBREAK()
#endif

#define HM_EXPAND_MACRO(x) x
#define HM_STRINGIFY_MACRO(x) #x


#define BIT(x) (1 << x)

#define HM_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Hummer {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}


	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Hummer/Core/Log.h"
#include "Hummer/Core/Assert.h"
