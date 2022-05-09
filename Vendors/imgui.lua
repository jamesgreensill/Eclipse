project ("imgui")
	kind ("StaticLib")
	language ("C")
	architecture ("x86_64")

    location(OutDir .. "Vendors/imgui")

    -- replace these
	targetdir("%{BuildLocation}%{prj.name}")
	objdir("%{BuildLocation}Imde/%{prj.name}")
	
	includedirs { "%{DependencyDir}imgui/", "%{DependencyDir}imgui/examples/", "%{DependencyDir}glad/include/", "%{DependencyDir}glfw/include/" }

	files
	{
		"%{DependencyDir}imgui/*.cpp",
		"%{DependencyDir}imgui/backends/imgui_impl_glfw.cpp",
		"%{DependencyDir}imgui/backends/imgui_impl_opengl3.cpp"
	}

	defines 
	{
		"IMGUI_IMPL_OPENGL_LOADER_GLAD"
	}
    
	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		defines
		{
			"_IMGUI_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		defines 
		{ 
			"_IMGUI_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"