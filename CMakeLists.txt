cmake_minimum_required(VERSION 3.10)
project(Starfarm)
set(CMAKE_CXX_STANDARD 17)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(EXECUTABLE_NAME "Starfarm")


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
add_library(ecs STATIC ${ECS_SOURCES})


set(RESSOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/resource")
add_definitions(-DTEXTURE_DIRECTORY="${RESSOURCE_DIRECTORY}/texture/")
add_definitions(-DMUSIC_DIRECTORY="${RESSOURCE_DIRECTORY}/music/")
add_definitions(-DSOUND_DIRECTORY="${RESSOURCE_DIRECTORY}/sound/")
add_definitions(-DFONT_DIRECTORY="${RESSOURCE_DIRECTORY}/font/")

include_directories(ECS/src/Entity)
include_directories(ECS/src/Component)
include_directories(ECS/src/System)
set(STARFARM_SOURCES
    Starfarm/src/RessourceManager.cpp Starfarm/src/RessourceManager.hpp
    Starfarm/src/Game.cpp Starfarm/src/Game.hpp
    Starfarm/src/Entity/Player/PlayerEntity.hpp
    Starfarm/src/Component/TransformComponent.cpp Starfarm/src/Component/TransformComponent.hpp
    Starfarm/src/System/RendererSystem.cpp Starfarm/src/System/RendererSystem.hpp
    #    Starfarm/src/GameTest.cpp Starfarm/src/GameTest.hpp
    Starfarm/src/Entity/Player/PlayerBehaviour.cpp Starfarm/src/Entity/Player/PlayerBehaviour.hpp
    Starfarm/src/Component/MonoBehaviourComponent.cpp Starfarm/src/Component/MonoBehaviourComponent.hpp
    Starfarm/src/System/BehaviourSystem.cpp Starfarm/src/System/BehaviourSystem.hpp
    Starfarm/src/Entity/GameObject.cpp Starfarm/src/Entity/GameObject.hpp
    Starfarm/src/Component/TextComponent.cpp Starfarm/src/Component/TextComponent.hpp
    Starfarm/src/Component/BaseRendererComponent.cpp Starfarm/src/Component/BaseRendererComponent.hpp
    Starfarm/src/Component/SpriteComponent.cpp Starfarm/src/Component/SpriteComponent.hpp
    Starfarm/src/Entity/FPSCounter/FpsCounter.cpp Starfarm/src/Entity/FPSCounter/FpsCounter.hpp
    Starfarm/src/Entity/FPSCounter/FpsCounterBehaviour.cpp Starfarm/src/Entity/FPSCounter/FpsCounterBehaviour.hpp Starfarm/src/Entity/Missile/Missile.cpp Starfarm/src/Entity/Missile/Missile.hpp Starfarm/src/Entity/Missile/MissileBehaviour.cpp Starfarm/src/Entity/Missile/MissileBehaviour.hpp Starfarm/src/System/EventSystem.cpp Starfarm/src/System/EventSystem.hpp Starfarm/src/Event/Event.cpp Starfarm/src/Event/Event.hpp Starfarm/src/Event/EventHandler.cpp Starfarm/src/Event/EventHandler.hpp)

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(SFML_DIR "SFML-2.5.1-visual64/lib/cmake/SFML")
        set(SFML_DLLS "${CMAKE_SOURCE_DIR}/SFML-2.5.1-visual64/bin")
        include_directories(SFML-2.5.1-visual64/include)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(SFML_DIR "SFML-2.5.1-visual32/lib/cmake/SFML")
        set(SFML_DLLS "${CMAKE_SOURCE_DIR}/SFML-2.5.1-visual32/bin")
        include_directories(SFML-2.5.1-visual32/include)
    endif ()
elseif (UNIX)
    set(SFML_DIR "SFML-2.5.1-gcc64/lib/cmake/SFML")
    include_directories(SFML-2.5.1-gcc64/include)
endif ()

find_package(SFML 2.5 COMPONENTS graphics audio window network system REQUIRED)

option(STARFARM_EXECUTABLE "Compile Starfarm binary" OFF)
if (STARFARM_EXECUTABLE)
    if (WIN32)
	    add_executable(${EXECUTABLE_NAME} ${STARFARM_SOURCES} Starfarm/src/windows_main.cpp)

		add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
			               COMMAND ${CMAKE_COMMAND} -E copy_directory
				           ${SFML_DLLS}
					       ${EXECUTABLE_OUTPUT_PATH}
                           )
	elseif (UNIX)
	    add_executable(${EXECUTABLE_NAME} ${STARFARM_SOURCES} Starfarm/src/unix_main.cpp)
    endif ()

    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resource
                       ${EXECUTABLE_OUTPUT_PATH}
                       )
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

    install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
endif ()


add_library(coverage_config INTERFACE)
option(CODE_COVERAGE "Enable coverage reporting" OFF)
if (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(coverage_config INTERFACE
                           -O0
                           -g
                           --coverage
                           )
    if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else ()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif ()
endif ()

option(BUILD_TESTING "Build testing tree" ON)
if (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    add_subdirectory(tests)
endif ()
