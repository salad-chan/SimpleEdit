workspace "SimpleEdit"
	architecture "x64"
	configurations { 
		"Debug", 
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SimpleEdit"
	kind "ConsoleApp"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}")
	objdir ( "bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"vendor/imgui/**.h",
		"vendor/imgui/**.cpp",
		"src/**.cpp",
		"src/**.h",
		"vendor/glad/src/**.c"
	}

	includedirs {
		"vendor/GLFW/include",
		"vendor/imgui",
		"vendor/glad/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		links { "glfw3" }

	libdirs {
		"vendor/GLFW/lib-vc2022"
	}

filter "configurations:Debug"
	defines { "DEBUG" }
	symbols "On"

filter "configurations:Release"
	defines { "NDEBUG" }
	optimize "On"
