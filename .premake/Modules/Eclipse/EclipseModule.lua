function CreateModule(name, dependencies)
project(name)

    kind("StaticLib")
    language("C++")
    architecture("x86_64")
    staticruntime("on")

    location("../" .. OutDir .. "Modules/" .. name)

    files
    {
        "./**.cpp",
        "./**.h",
        "./**.hpp"
    }
    
    includedirs {
        "%{wks.location}",
        IncludeDir, -- Array of include directories
        "./include"
    }

    links(dependencies) -- Library dependencies

    -- location("../" .. OutDir .. "Modules/" .. name)

    targetdir("%{BuildLocation}%{prj.name}")
    objdir("%{BuildLocation}Imde/%{prj.name}")


    filter "configurations:Debug"
    runtime "Debug"
    symbols "On"

    filter "configurations:Release"
    runtime  "Release"
    optimize "On"

    filter ""

end