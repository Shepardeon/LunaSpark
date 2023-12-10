-- premake5.lua
workspace "LunaSpark"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Sandbox"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "LunaSpark"
	include "LunaSpark/Build-Engine.lua"
group ""

include "Sandbox/Build-App.lua"