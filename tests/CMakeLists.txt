set(STARFARM_TEST_SOURCES
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/Game.cpp ../Starfarm/src/Game.hpp
    ../Starfarm/src/Player/PlayerEntity.hpp
    ../Starfarm/src/Component/TransformComponent.cpp ../Starfarm/src/Component/TransformComponent.hpp
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/System/TransformSystem.cpp ../Starfarm/src/System/TransformSystem.hpp
    ../Starfarm/src/Component/RendererComponent.cpp ../Starfarm/src/Component/RendererComponent.hpp
    ../Starfarm/src/System/RendererSystem.cpp ../Starfarm/src/System/RendererSystem.hpp
    ../Starfarm/src/GameTest.cpp ../Starfarm/src/GameTest.hpp
    )

option(CLION "Enable CLion" ON)
if (CLION)
    add_executable(tests main.cpp ${STARFARM_SOURCES})
else ()
    add_executable(tests main.cpp ${STARFARM_TEST_SOURCES})
endif ()
target_link_libraries(tests PRIVATE coverage_config)
target_link_libraries(tests PRIVATE sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

add_test(NAME exec_tests COMMAND tests)
