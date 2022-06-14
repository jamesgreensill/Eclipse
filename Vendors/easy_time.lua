project("easy_time")
    kind(DependencyType)
    language("C")
  
    architecture "x86_64"

    location(OutDir .. "Vendors/easy_time")

    targetdir("%{BuildLocation}%{prj.name}")
    objdir("%{BuildLocation}Imde/%{prj.name}")

    staticruntime "On"

    files
    {
        "%{DependencyDir}easy_time/include/**",
    }

    includedirs { "%{DependencyDir}easy_time/include" }

    filter "system:windows"
		systemversion "latest" -- Windows SDK

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		runtime  "Release"
		optimize "On"