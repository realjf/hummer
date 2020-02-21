#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hummer {
	class HUMMER_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define HM_CORE_ERROR(...) ::Hummer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HM_CORE_WARN(...) ::Hummer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HM_CORE_INFO(...) ::Hummer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HM_CORE_TRACE(...) ::Hummer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HM_CORE_FATAL(...) ::Hummer::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define HM_ERROR(...) ::Hummer::Log::GetClientLogger()->error(__VA_ARGS__)
#define HM_WARN(...) ::Hummer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HM_INFO(...) ::Hummer::Log::GetClientLogger()->info(__VA_ARGS__)
#define HM_TRACE(...) ::Hummer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HM_FATAL(...) ::Hummer::Log::GetClientLogger()->fatal(__VA_ARGS__)