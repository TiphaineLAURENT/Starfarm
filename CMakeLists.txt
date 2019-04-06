cmake_minimum_required(VERSION 3.10)
project(ECS)

set(CMAKE_CXX_STANDARD  17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

set(ECS_SOURCE_DIRECTORY ECS/src)
set(ECS_SOURCES
        ECS/src/Entity/IEntity.cpp ECS/src/Entity/IEntity.hpp
        ECS/src/util/util.hpp
        ECS/src/Component/ComponentManager.cpp ECS/src/Component/ComponentManager.hpp
        ECS/src/Component/ComponentContainer.cpp ECS/src/Component/ComponentContainer.hpp
        ECS/src/Component/IComponent.cpp ECS/src/Component/IComponent.hpp
        ECS/src/Entity/Entity.cpp ECS/src/Entity/Entity.hpp
        ECS/src/Component/Component.cpp ECS/src/Component/Component.hpp
        ECS/src/Component/IComponentContainer.cpp ECS/src/Component/IComponentContainer.hpp ECS/src/Entity/EntityManager.cpp ECS/src/Entity/EntityManager.hpp ECS/src/Entity/IEntityContainer.cpp ECS/src/Entity/IEntityContainer.hpp ECS/src/Entity/EntityContainer.cpp ECS/src/Entity/EntityContainer.hpp)
add_library(ecs STATIC ${ECS_SOURCES})

add_executable(test test/src/main.cpp)

set_target_properties(ecs PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(test ecs)
