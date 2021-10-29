project "Logger"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

	files {
		"logger.h",
		"logger.cpp",
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		defines {
			"_DEBUG"
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

		defines {
			"_RELEASE"
		}