include "Dependencies.lua"

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


group "Dependencies"
	include "Hummer/vendor/GLFW"
	include "Hummer/vendor/GLAD"
	include "Hummer/vendor/imgui"
	include "Hummer/vendor/yaml-cpp"
group ""

include "Hummer"
include "Sandbox"
include "Hummernut"