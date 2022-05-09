project("glad")
    kind(DependencyType)
    language("C")
  
    architecture "x86_64"

    location(OutDir .. "Vendors/glad")

    targetdir("%{BuildLocation}%{prj.name}")
    objdir("%{BuildLocation}Imde/%{prj.name}")

    staticruntime "On"

    files
    {
        "%{DependencyDir}glad/include/glad/glad.h",
		    "%{DependencyDir}glad/include/KHR/khrplatform.h",
		    "%{DependencyDir}glad/src/glad.c"
    }

    includedirs { "%{DependencyDir}glad/include" }

    filter "system:windows"
		systemversion "latest" -- Windows SDK

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		runtime  "Release"
		optimize "On"