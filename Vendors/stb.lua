project("stb")
    kind(DependencyType)
    language("C")
    architecture("x86_64")

	location(OutDir .. "Vendors/stb")


    targetdir("%{BuildLocation}%{prj.name}")
	objdir("%{BuildLocation}Imde/%{prj.name}")

    includedirs { "%{DependencyDir}stb/" }
    
    files
	{
		"%{DependencyDir}stb/*"
	}

    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"