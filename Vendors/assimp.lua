project ("assimp")
  kind ("StaticLib")
  language ("C++")
  staticruntime ("on")

  location(OutDir .. "Vendors/assimp")

  targetdir("%{BuildLocation}%{prj.name}")
  objdir("%{BuildLocation}Imde/%{prj.name}")

  defines {
    "ASSIMP_BUILD_NO_OWN_ZLIB",

  "ASSIMP_BUILD_NO_EXPORT",

  "ASSIMP_BUILD_NO_X_IMPORTER",
  "ASSIMP_BUILD_NO_3DS_IMPORTER",
  "ASSIMP_BUILD_NO_MD3_IMPORTER",
  "ASSIMP_BUILD_NO_MDL_IMPORTER",
  "ASSIMP_BUILD_NO_MD2_IMPORTER",
    -- "ASSIMP_BUILD_NO_PLY_IMPORTER",
    "ASSIMP_BUILD_NO_ASE_IMPORTER",
    -- "ASSIMP_BUILD_NO_OBJ_IMPORTER",
    "ASSIMP_BUILD_NO_AMF_IMPORTER",
    "ASSIMP_BUILD_NO_HMP_IMPORTER",
    "ASSIMP_BUILD_NO_SMD_IMPORTER",
    "ASSIMP_BUILD_NO_MDC_IMPORTER",
    "ASSIMP_BUILD_NO_MD5_IMPORTER",
    "ASSIMP_BUILD_NO_STL_IMPORTER",
    "ASSIMP_BUILD_NO_LWO_IMPORTER",
    "ASSIMP_BUILD_NO_DXF_IMPORTER",
    "ASSIMP_BUILD_NO_NFF_IMPORTER",
    "ASSIMP_BUILD_NO_RAW_IMPORTER",
    "ASSIMP_BUILD_NO_OFF_IMPORTER",
    "ASSIMP_BUILD_NO_AC_IMPORTER",
    "ASSIMP_BUILD_NO_BVH_IMPORTER",
    "ASSIMP_BUILD_NO_IRRMESH_IMPORTER",
    "ASSIMP_BUILD_NO_IRR_IMPORTER",
    "ASSIMP_BUILD_NO_Q3D_IMPORTER",
    "ASSIMP_BUILD_NO_B3D_IMPORTER",
    "ASSIMP_BUILD_NO_COLLADA_IMPORTER",
    "ASSIMP_BUILD_NO_TERRAGEN_IMPORTER",
    "ASSIMP_BUILD_NO_CSM_IMPORTER",
    "ASSIMP_BUILD_NO_3D_IMPORTER",
    "ASSIMP_BUILD_NO_LWS_IMPORTER",
    "ASSIMP_BUILD_NO_OGRE_IMPORTER",
    "ASSIMP_BUILD_NO_OPENGEX_IMPORTER",
    "ASSIMP_BUILD_NO_MS3D_IMPORTER",
    "ASSIMP_BUILD_NO_COB_IMPORTER",
    "ASSIMP_BUILD_NO_BLEND_IMPORTER",
    "ASSIMP_BUILD_NO_Q3BSP_IMPORTER",
    "ASSIMP_BUILD_NO_NDO_IMPORTER",
    "ASSIMP_BUILD_NO_IFC_IMPORTER",
    "ASSIMP_BUILD_NO_XGL_IMPORTER",
    -- "ASSIMP_BUILD_NO_FBX_IMPORTER",
    "ASSIMP_BUILD_NO_ASSBIN_IMPORTER",
    -- "ASSIMP_BUILD_NO_GLTF_IMPORTER",
    "ASSIMP_BUILD_NO_C4D_IMPORTER",
    "ASSIMP_BUILD_NO_3MF_IMPORTER",
    "ASSIMP_BUILD_NO_X3D_IMPORTER",
    "ASSIMP_BUILD_NO_MMD_IMPORTER",
    "ASSIMP_BUILD_NO_M3D_IMPORTER",
    "ASSIMP_BUILD_NO_IQM_IMPORTER",
    "ASSIMP_BUILD_NO_SIB_IMPORTER",

    -- "ASSIMP_BUILD_NO_MAKELEFTHANDED_PROCESS",
    -- "ASSIMP_BUILD_NO_FLIPUVS_PROCESS",
    -- "ASSIMP_BUILD_NO_FLIPWINDINGORDER_PROCESS",
    -- "ASSIMP_BUILD_NO_CALCTANGENTS_PROCESS",
    "ASSIMP_BUILD_NO_JOINVERTICES_PROCESS",
    -- "ASSIMP_BUILD_NO_TRIANGULATE_PROCESS",
    "ASSIMP_BUILD_NO_GENFACENORMALS_PROCESS",
    -- "ASSIMP_BUILD_NO_GENVERTEXNORMALS_PROCESS",
    "ASSIMP_BUILD_NO_REMOVEVC_PROCESS",
    "ASSIMP_BUILD_NO_SPLITLARGEMESHES_PROCESS",
    "ASSIMP_BUILD_NO_PRETRANSFORMVERTICES_PROCESS",
    "ASSIMP_BUILD_NO_LIMITBONEWEIGHTS_PROCESS",
    -- "ASSIMP_BUILD_NO_VALIDATEDS_PROCESS",
    "ASSIMP_BUILD_NO_IMPROVECACHELOCALITY_PROCESS",
    "ASSIMP_BUILD_NO_FIXINFACINGNORMALS_PROCESS",
    "ASSIMP_BUILD_NO_REMOVE_REDUNDANTMATERIALS_PROCESS",
    "ASSIMP_BUILD_NO_FINDINVALIDDATA_PROCESS",
    "ASSIMP_BUILD_NO_FINDDEGENERATES_PROCESS",
    "ASSIMP_BUILD_NO_SORTBYPTYPE_PROCESS",
    "ASSIMP_BUILD_NO_GENUVCOORDS_PROCESS",
    "ASSIMP_BUILD_NO_TRANSFORMTEXCOORDS_PROCESS",
    "ASSIMP_BUILD_NO_FINDINSTANCES_PROCESS",
    "ASSIMP_BUILD_NO_OPTIMIZEMESHES_PROCESS",
    "ASSIMP_BUILD_NO_OPTIMIZEGRAPH_PROCESS",
    "ASSIMP_BUILD_NO_SPLITBYBONECOUNT_PROCESS",
    "ASSIMP_BUILD_NO_DEBONE_PROCESS",
    "ASSIMP_BUILD_NO_EMBEDTEXTURES_PROCESS",
    "ASSIMP_BUILD_NO_GLOBALSCALE_PROCESS",
  "UNICODE",
  "_UNICODE",
  "_SCL_SECURE_NO_WARNINGS",
  "_CRT_SECURE_NO_WARNINGS",
  "ASSIMP_BUILD_DLL_EXPORT"
}

files
{
  "%{VendorDir}/assimp/include/**",
  "%{VendorDir}/assimp/code/Common/**",
  "%{VendorDir}/assimp/code/Material/**",
  "%{VendorDir}/assimp/code/PostProcessing/**",
  "%{VendorDir}/assimp/code/AssetLib/FBX/**",
  "%{VendorDir}/assimp/code/AssetLib/OBJ/**",
  "%{VendorDir}/assimp/code/AssetLib/PLY/**",
  "%{VendorDir}/assimp/code/AssetLib/glTF/**",
  "%{VendorDir}/assimp/code/AssetLib/glTF2/**",
  "%{VendorDir}/assimp/contrib/pugixml/**",
  "%{VendorDir}/assimp/contrib/zlib/*.c",
  "%{VendorDir}/assimp/contrib/zlib/*.h",
  "%{VendorDir}/assimp/contrib/stb/**"
}

includedirs
{
  "%{VendorDir}/assimp",
  "%{VendorDir}/assimp/code",
  "%{VendorDir}/assimp/include",
    "%{VendorDir}/assimp/contrib",
    "%{VendorDir}/assimp/contrib/zlib",
    "%{VendorDir}/assimp/contrib/unzip",
    "%{VendorDir}/assimp/contrib/irrXML",
    "%{VendorDir}/assimp/contrib/pugixml/src",
    "%{VendorDir}/assimp/contrib/rapidjson/include",
}

  prebuildcommands
  {
      "{COPYFILE} \"%{wks.location}../Vendors/AssimpHeaders/config.h\" \"%{wks.location}../Vendors/assimp/include/assimp/config.h\"",
      "{COPYFILE} \"%{wks.location}../Vendors/AssimpHeaders/zconf.h\" \"%{wks.location}../Vendors/assimp/contrib/zlib/zconf.h\"",
      "{COPYFILE} \"%{wks.location}../Vendors/AssimpHeaders/revision.h\" \"%{wks.location}../Vendors/assimp/revision.h\""
  }

  filter "system:windows"
  systemversion "latest"
  defines { "WIN32", "_WINDOWS", "WIN32_LEAN_AND_MEAN" }

filter  "configurations:Debug"
     runtime "Debug"
     symbols "On"
     defines { }

filter  "configurations:Release"
     runtime "Release"
     optimize "On"