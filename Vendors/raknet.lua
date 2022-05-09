project("raknet")
    kind("StaticLib")
    language("C++")
    architecture("x86_64")
    staticruntime("on")

    location(OutDir .. "Vendors/raknet")

    targetdir("%{BuildLocation}%{prj.name}")
	objdir("%{BuildLocation}Imde/%{prj.name}")
    
    files 
    {
        "%{DependencyDir}raknet/Source/**"
    }

    includedirs 
    {
        "%{DependencyDir}raknet/Source",
        "%{DependencyDir}raknet/DependentExtensions/openssl-1.0.0d/include",
        "%{DependencyDir}raknet/DependentExtensions"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"