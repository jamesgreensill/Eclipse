project ("glm")
	kind ("StaticLib")
	language ("C")
	architecture ("x86_64")

	location(OutDir .. "Vendors/glm")


    -- replace these.
	targetdir("%{BuildLocation}%{prj.name}")
	objdir("%{BuildLocation}Imde/%{prj.name}")
	
	includedirs { "%{DependencyDir}glm/" }

	files
	{
		"%{DependencyDir}glm/glm/**"
		--"glm/glm/**"
	}
    
	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		defines
		{
			"_GLM_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		defines 
		{ 
			"_GLM_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"