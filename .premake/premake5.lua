-- solution
    -- projects
        -- demo-project
            -- data
            -- docs
            -- imde
            -- include
            -- libs
            -- src
            -- tests
            -- file.project
    -- engine
        -- engine-module
            -- data
            -- docs
            -- examples
            -- extras
            -- imde
            -- include
            -- libs
            -- src
            -- tests
            -- tools
            -- file.project
    -- dependencies
        -- bin
        -- lib
        -- header
        -- dll
    -- build
    -- .cloc
    -- .git
    -- .dirgen
    -- .vs
    -- .premake

-- premake5.lua


-- global variables
DependencyType = "StaticLib"
OutDir = "../Build/"

include "./Modules/Eclipse/EclipseProject.lua"
include "./Modules/Eclipse/EclipseModule.lua"
    
workspace "Eclipse"
    location("../Build")
    architecture("x86_64")
    configurations { "Debug", "Release" }

    flags {"MultiProcessorCompile"}

    BuildLocation = "%{wks.location}/%{cfg.buildcfg}/"
    
    filter "configurations:Release"
        defines {"NDEBUG"}
    filter {}
    
    include "vendors.lua"
    IncludeDir["EclipseEngine"] = "%{wks.location}/../Engine/"

    -- Projects File (This will load all projects defined.)
    group "Projects"
        include "../Projects/Projects.lua"
    -- Modules File (This will load all modules defined.)
    group "Modules"
        include "../Engine/Modules.lua"
    group ""

