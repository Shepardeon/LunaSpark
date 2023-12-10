-- Either have the lib compiled for multiple OS
-- or build SDL with premake (but I can't be bothered to do it now)
IncludeDir = {}
IncludeDir['winSDL2'] = '%{wks.location}/LunaSpark/Vendor/Windows/SDL2/include'

LibraryDir = {}
LibraryDir['winSDL2'] = '%{wks.location}/LunaSpark/Vendor/Windows/SDL2/lib/x64'

Library = {}
Library['winSDL2'] = '%{LibraryDir.winSDL2}/SDL2.lib'
Library['winSDL2main'] = '%{LibraryDir.winSDL2}/SDL2main.lib'