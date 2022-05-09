project("termcolor")
    kind("StaticLib")
    language("C++")
    architecture("x86_64")

    location(OutDir .. "Vendors/termcolor")

    targetdir("%{BuildLocation}%{prj.name}")
	objdir("%{BuildLocation}Imde/%{prj.name}")
    flags {"MultiProcessorCompile"}

    includedirs { "%{DependencyDir}termcolor/include" }

    files
    {
        "%{DependencyDir}termcolor/include/termcolor/**"   
    }

    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
