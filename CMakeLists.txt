cmake_minimum_required(VERSION 3.25)
project(TesingGame)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/libs-vc/SDL2-2.26.5/include)
set(SDL2_LIB_DIR C:/libs-vc/SDL2-2.26.5/lib/x64)

set(SDL2_IMAGE_INCLUDE_DIR C:/libs-vc/SDL2_image-2.6.3/include)
set(SDL2_IMAGE_LIB_DIR C:/libs-vc/SDL2_image-2.6.3/lib/x64)

set(SDL2_TTF_INCLUDE_DIR C:/libs-vc/SDL2_ttf-2.20.2/include)
set(SDL2_TTF_LIB_DIR C:/libs-vc/SDL2_ttf-2.20.2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

include_directories(${SDL2_TTF_INCLUDE_DIR})
link_directories(${SDL2_TTF_LIB_DIR})


add_executable(TesingGame main.cpp Engine/Engine.cpp Engine/Engine.h Managers/TextureManager.cpp Managers/TextureManager.h GameObjects/GameObject.cpp GameObjects/GameObject.h GameObjects/Player/Player.cpp GameObjects/Player/Player.h Managers/CollisionManager.cpp Managers/CollisionManager.h Managers/WorldManager.cpp Managers/WorldManager.h TerrainObjects/TerrainObject.cpp TerrainObjects/TerrainObject.h GameObjects/Camera/Camera.cpp GameObjects/Camera/Camera.h GameObjects/Quarries/Quarry.cpp GameObjects/Quarries/Quarry.h GameObjects/MineCave/MineCave.cpp GameObjects/MineCave/MineCave.h GameObjects/GUI/BuildPanel.cpp GameObjects/GUI/BuildPanel.h GameObjects/Terrain/Terrain.cpp GameObjects/Terrain/Terrain.h Managers/EventManager.cpp Managers/EventManager.h GameObjects/GUI/ResourcePanel/ResourcePanel.cpp GameObjects/GUI/ResourcePanel/ResourcePanel.h GameObjects/Base/Base.cpp GameObjects/Base/Base.h GameObjects/SplashGun/SplashGun.cpp GameObjects/SplashGun/SplashGun.h)

target_link_libraries(TesingGame SDL2main SDL2 SDL2_image SDL2_ttf)




