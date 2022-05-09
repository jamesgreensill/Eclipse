VendorDir = "%{wks.location}/../Vendors/"
-- location
-- solution_root/Engine/Vendors

IncludeDir = {}

-- IncludeDir[include name] = "%{VendorDir}folder name"
IncludeDir["GLM"] = VendorDir .. "glm"
IncludeDir["STB"] = VendorDir .. "stb"
IncludeDir["ImGUI"] = VendorDir .. "imgui"
IncludeDir["GLAD"] = VendorDir .. "glad/include"
IncludeDir["GLFW"] = VendorDir .. "glfw/include"
IncludeDir["Assimp"] = VendorDir .. "assimp/include"
IncludeDir["termcolor"] = VendorDir .. "termcolor/include"
IncludeDir["RakNet"] = VendorDir .. "raknet/Source"

group("Vendors")
        include("../Vendors/glm.lua")
        include("../Vendors/stb.lua")
        include("../Vendors/imgui.lua")
        include("../Vendors/glad.lua")
        include("../Vendors/glfw.lua")
        include("../Vendors/assimp.lua")
        include("../Vendors/termcolor.lua")
        include("../Vendors/raknet.lua")
group ""