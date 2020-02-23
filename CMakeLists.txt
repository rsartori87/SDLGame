cmake_minimum_required(VERSION 3.0)
project(SDLLearn LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(SDLLearn
  src/main.cpp
  src/Game.cpp
  src/Game.h
  src/TextureManager.h
  src/TextureManager.cpp
  src/GameObject.h
  src/Player.h
  src/Player.cpp
  src/Enemy.h
  src/Enemy.cpp
  src/LoaderParams.h
  src/SDLGameObject.h
  src/SDLGameObject.cpp
  src/Vector2D.h
  src/InputHandler.h
  src/InputHandler.cpp
  src/GameState.h
  src/MenuState.h
  src/MenuState.cpp
  src/PlayState.h
  src/PlayState.cpp
  src/GameStateMachine.h
  src/GameStateMachine.cpp
  src/MenuButton.h
  src/MenuButton.cpp)

target_include_directories(SDLLearn PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(SDLLearn PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
