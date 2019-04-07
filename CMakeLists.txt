cmake_minimum_required(VERSION 3.10)
project(Starfarm)
set(CMAKE_CXX_STANDARD  17)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

set(ECS_SOURCE_DIRECTORY ECS/src)
set(ECS_SOURCES
        ECS/src/Entity/IEntity.cpp ECS/src/Entity/IEntity.hpp
        ECS/src/util/util.hpp
        ECS/src/Component/ComponentManager.cpp ECS/src/Component/ComponentManager.hpp
        ECS/src/Component/ComponentContainer.cpp ECS/src/Component/ComponentContainer.hpp
        ECS/src/Component/IComponent.cpp ECS/src/Component/IComponent.hpp
        ECS/src/Entity/Entity.cpp ECS/src/Entity/Entity.hpp
        ECS/src/Component/Component.cpp ECS/src/Component/Component.hpp
        ECS/src/Component/IComponentContainer.cpp ECS/src/Component/IComponentContainer.hpp
        ECS/src/Entity/EntityManager.cpp ECS/src/Entity/EntityManager.hpp
        ECS/src/Entity/IEntityContainer.cpp ECS/src/Entity/IEntityContainer.hpp
        ECS/src/Entity/EntityContainer.cpp ECS/src/Entity/EntityContainer.hpp)

set(STARFARM_SOURCES
        Starfarm/src/main.cpp
        Starfarm/src/Window.cpp Starfarm/src/Window.hpp)

set(EXECUTABLE_NAME "Starfarm")

add_library(ecs STATIC ${ECS_SOURCES})
add_executable(${EXECUTABLE_NAME} ${STARFARM_SOURCES})

if (WIN32)
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin-visual64)
		set(SFML_DIR "SFML-2.5.1-visual64/lib/cmake/SFML")
		include_directories(SFML-2.5.1-visual64/include)
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin-visual32)
		set(SFML_DIR "SFML-2.5.1-visual32/lib/cmake/SFML")
		include_directories(SFML-2.5.1-visual32/include)
	endif()
elseif (UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin-gcc64)
    set(SFML_DIR "SFML-2.5.1-gcc64/lib/cmake/SFML")
    include_directories(SFML-2.5.1-gcc64/include)
endif()

find_package(SFML 2.5 COMPONENTS graphics audio window network system REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)