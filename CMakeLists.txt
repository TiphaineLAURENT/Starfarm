cmake_minimum_required(VERSION 3.10)
project(Starfarm)

set(CMAKE_CXX_STANDARD  17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

set(ECS_SOURCE_DIRECTORY ECS/src)
set(ECS_SOURCES
        ECS/src/Entity/IEntity.cpp ECS/src/Entity/IEntity.hpp
        ECS/src/util/util.hpp
        ECS/src/Component/ComponentManager.cpp ECS/src/Component/ComponentManager.hpp
        ECS/src/Component/ComponentContainer.cpp ECS/src/Component/ComponentContainer.hpp
        ECS/src/Component/IComponent.cpp ECS/src/Component/IComponent.hpp
        ECS/src/Entity/Entity.cpp ECS/src/Entity/Entity.hpp
        ECS/src/Component/Component.cpp ECS/src/Component/Component.hpp
        ECS/src/Component/IComponentContainer.cpp
        ECS/src/Component/IComponentContainer.hpp
        ECS/src/Entity/EntityManager.cpp
        ECS/src/Entity/EntityManager.hpp
        ECS/src/Entity/IEntityContainer.cpp
        ECS/src/Entity/IEntityContainer.hpp
        ECS/src/Entity/EntityContainer.cpp
        ECS/src/Entity/EntityContainer.hpp
        Starfarm/src/main.cpp)
add_library(ecs STATIC ${ECS_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics audio window network system REQUIRED)
include_directories(SFML-2.5.1/include)
add_executable(Starfarm Starfarm/src/main.cpp)
target_link_libraries(Starfarm sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)
