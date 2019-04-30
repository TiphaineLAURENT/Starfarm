set(STARFARM_MANUAL_SOURCES
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/Game.cpp ../Starfarm/src/Game.hpp
    ../Starfarm/src/Player/PlayerEntity.hpp
    ../Starfarm/src/Component/TransformComponent.cpp ../Starfarm/src/Component/TransformComponent.hpp
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/Component/RendererComponent.cpp ../Starfarm/src/Component/RendererComponent.hpp
    ../Starfarm/src/System/RendererSystem.cpp ../Starfarm/src/System/RendererSystem.hpp
    #    ../Starfarm/src/GameTest.cpp ../Starfarm/src/GameTest.hpp
    ../Starfarm/src/Player/PlayerBehaviour.cpp ../Starfarm/src/Player/PlayerBehaviour.hpp
    ../Starfarm/src/Component/MonoBehaviourComponent.cpp ../Starfarm/src/Component/MonoBehaviourComponent.hpp
    ../Starfarm/src/System/BehaviourSystem.cpp ../Starfarm/src/System/BehaviourSystem.hpp
    ../Starfarm/src/Entity/GameObject.cpp ../Starfarm/src/Entity/GameObject.hpp
    ../Starfarm/src/Component/TextComponent.cpp ../Starfarm/src/Component/TextComponent.hpp
    ../Starfarm/src/Component/BaseRendererComponent.cpp ../Starfarm/src/Component/BaseRendererComponent.hpp ../Starfarm/src/Component/SpriteComponent.cpp ../Starfarm/src/Component/SpriteComponent.hpp ../Starfarm/src/Entity/FpsCounter.cpp ../Starfarm/src/Entity/FpsCounter.hpp)

option(MANUAL_TEST "Enable CLion" ON)
if (MANUAL_TEST)
    add_executable(tests main.cpp ${STARFARM_MANUAL_SOURCES})
else ()
    add_executable(tests main.cpp ${STARFARM_SOURCES})
endif ()
target_link_libraries(tests coverage_config)
target_link_libraries(tests sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

add_test(NAME exec_tests COMMAND tests --success)
