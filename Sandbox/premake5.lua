project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"


	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Hummer/vendor/spdlog/include",
		"%{wks.location}/Hummer/src",
		"%{wks.location}/Hummer/vendor",
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