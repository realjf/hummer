workspace "Hummer"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hummer"
	location "Hummer"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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
		systemversion "10.0.17763.0"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL"
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
