workspace "Hummer"
	architecture "x86_64"
	startproject "Hummernut"

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
IncludeDir["ImGui"] = "Hummer/vendor/imgui"
IncludeDir["glm"] = "Hummer/vendor/glm"
IncludeDir["stb"] = "Hummer/vendor/stb_image"
IncludeDir["entt"] = "Hummer/vendor/entt/include"

group "Dependencies"
	include "Hummer/vendor/GLFW"
	include "Hummer/vendor/GLAD"
	include "Hummer/vendor/imgui"
group ""


project "Hummer"
	location "Hummer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "hmpch.h"
	pchsource "Hummer/src/hmpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}


	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.entt}",
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

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


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
		"Hummer/src",
		"Hummer/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
	}

	links
	{
		"Hummer"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "on"

project "Hummernut"
	location "Hummernut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


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
		"Hummer/src",
		"Hummer/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Hummer"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "on"
