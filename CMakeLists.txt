cmake_minimum_required(VERSION 3.10)
project(Starfarm)
set(CMAKE_CXX_STANDARD  17)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

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
        ECS/src/Entity/EntityContainer.cpp ECS/src/Entity/EntityContainer.hpp
        ECS/src/System/ISystem.cpp ECS/src/System/ISystem.hpp
        ECS/src/System/System.cpp ECS/src/System/System.hpp
        ECS/src/System/SystemManager.cpp ECS/src/System/SystemManager.hpp
        ECS/src/System/SimpleSystemManager.cpp ECS/src/System/SimpleSystemManager.hpp
        )

set(RESSOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/Starfarm/ressource")
add_definitions(-DTEXTURE_DIRECTORY="${RESSOURCE_DIRECTORY}/texture")
add_definitions(-DMUSIC_DIRECTORY="${RESSOURCE_DIRECTORY}/music")
add_definitions(-DSOUND_DIRECTORY="${RESSOURCE_DIRECTORY}/sound")
add_definitions(-DFONT_DIRECTORY="${RESSOURCE_DIRECTORY}/font")

include_directories(ECS/src/Entity)
include_directories(ECS/src/Component)
include_directories(ECS/src/System)
set(STARFARM_SOURCES
        Starfarm/src/main.cpp
        Starfarm/src/RessourceManager.cpp Starfarm/src/RessourceManager.hpp
		Starfarm/src/Game.cpp Starfarm/src/Game.hpp
        Starfarm/src/Player/PlayerEntity.hpp
        Starfarm/src/Component/TransformComponent.cpp Starfarm/src/Component/TransformComponent.hpp
		Starfarm/src/RessourceManager.cpp Starfarm/src/RessourceManager.hpp
        Starfarm/src/System/TransformSystem.cpp Starfarm/src/System/TransformSystem.hpp
		Starfarm/src/Component/RendererComponent.cpp Starfarm/src/Component/RendererComponent.hpp
		Starfarm/src/System/RendererSystem.cpp Starfarm/src/System/RendererSystem.hpp
		Starfarm/src/GameTest.cpp Starfarm/src/GameTest.hpp)

add_library(ecs STATIC ${ECS_SOURCES})

set(EXECUTABLE_NAME "Starfarm")
add_executable(${EXECUTABLE_NAME} ${STARFARM_SOURCES})

if (WIN32)
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(SFML_DIR "SFML-2.5.1-visual64/lib/cmake/SFML")
		set(SFML_DLLS "${CMAKE_SOURCE_DIR}/SFML-2.5.1-visual64/bin")
		include_directories(SFML-2.5.1-visual64/include)
	elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(SFML_DIR "SFML-2.5.1-visual32/lib/cmake/SFML")
		set(SFML_DLLS "${CMAKE_SOURCE_DIR}/SFML-2.5.1-visual32/bin")
		include_directories(SFML-2.5.1-visual32/include)
	endif()
	add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
		${SFML_DLLS}
		${EXECUTABLE_OUTPUT_PATH}
	)
elseif (UNIX)
    set(SFML_DIR "SFML-2.5.1-gcc64/lib/cmake/SFML")
    include_directories(SFML-2.5.1-gcc64/include)
endif()
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resource
		${EXECUTABLE_OUTPUT_PATH}
)

find_package(SFML 2.5 COMPONENTS graphics audio window network system REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
