workspace "Hummer"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"] = "Hummer/vendor/GLFW/include"
IncludeDir["Glad"] = "Hummer/vendor/Glad/include"
IncludeDir["ImGui"] = "Hummer/vendor/imgui/include"

include "Hummer/vendor/GLFW"
include "Hummer/vendor/GLAD"


project "Hummer"
	location "Hummer"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "hmpch.h"
	pchsource "Hummer/src/hmpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		buildoptions "/MD"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hummer/vendor/spdlog/include",
		"Hummer/src"
	}

	links
	{
		"Hummer"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"

		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		symbols "On"
