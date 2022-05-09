function CreateSolution(name)

-- generate all modules
-- generate engine
-- generate 

workspace(name)
    location "../build"
    architecture "x86_64"
    configurations {"Debug", "Release"}

    filter "configurations:Release"
            defines {"NDEBUG"}
    
end