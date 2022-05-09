function CreateProject(name, dependencies, workingDir)

project(name)

    kind "ConsoleApp"
    language "C++"
    staticruntime("on")

    location("../" .. OutDir .. "Projects/" .. name)

    targetdir("%{BuildLocation}%{prj.name}")
    objdir("%{BuildLocation}Imde/%{prj.name}")

    if workingDir == nil then
        workingDir = "%{BuildLocation}%{prj.name}"
    end

    print("Working Dir: " .. workingDir)
    debugdir(workingDir)

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

    links { dependencies } -- Library dependencies

    filter "configurations:Debug"
       defines { "DEBUG" }
       symbols "On"

    filter "configurations:Release"
       defines { "NDEBUG" }
       optimize "On"
    filter ""
end
