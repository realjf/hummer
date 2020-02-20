#pragma once

#ifdef HM_PLATFORM_WINDOWS
#ifdef HM_BUILD_DLL
#define HUMMER_API __declspec(dllexport) 
#else
#define HUMMER_API __declspec(dllimport)
#endif // HM_BUILD_DLL
#else
#error Hummer only support windows!
#endif // HM_PLATFORM_WINDOWS

