set(STARFARM_MANUAL_SOURCES
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/Game.cpp ../Starfarm/src/Game.hpp
    ../Starfarm/src/Entity/Player/PlayerEntity.hpp
    ../Starfarm/src/Component/TransformComponent.cpp ../Starfarm/src/Component/TransformComponent.hpp
    ../Starfarm/src/RessourceManager.cpp ../Starfarm/src/RessourceManager.hpp
    ../Starfarm/src/Component/RendererComponent.cpp ../Starfarm/src/Component/RendererComponent.hpp
    ../Starfarm/src/System/RendererSystem.cpp ../Starfarm/src/System/RendererSystem.hpp
    ../Starfarm/src/Entity/Player/PlayerBehaviour.cpp ../Starfarm/src/Entity/Player/PlayerBehaviour.hpp
    ../Starfarm/src/Component/MonoBehaviourComponent.cpp ../Starfarm/src/Component/MonoBehaviourComponent.hpp
    ../Starfarm/src/System/BehaviourSystem.cpp ../Starfarm/src/System/BehaviourSystem.hpp
    ../Starfarm/src/Entity/GameObject.cpp ../Starfarm/src/Entity/GameObject.hpp
    ../Starfarm/src/Component/TextComponent.cpp ../Starfarm/src/Component/TextComponent.hpp
    ../Starfarm/src/Component/BaseRendererComponent.cpp ../Starfarm/src/Component/BaseRendererComponent.hpp
    ../Starfarm/src/Component/SpriteComponent.cpp ../Starfarm/src/Component/SpriteComponent.hpp
    ../Starfarm/src/Entity/FPSCounter/FpsCounter.cpp ../Starfarm/src/Entity/FPSCounter/FpsCounter.hpp
    ../Starfarm/src/Entity/FPSCounter/FpsCounterBehaviour.cpp ../Starfarm/src/Entity/FPSCounter/FpsCounterBehaviour.hpp ../Starfarm/src/Entity/Missile/Missile.cpp ../Starfarm/src/Entity/Missile/Missile.hpp ../Starfarm/src/Entity/Missile/MissileBehaviour.cpp ../Starfarm/src/Entity/Missile/MissileBehaviour.hpp)

option(MANUAL_TEST "Enable CLion" ON)
if (MANUAL_TEST)
    add_executable(tests main.cpp ${STARFARM_MANUAL_SOURCES})
else ()
    add_executable(tests main.cpp ${STARFARM_SOURCES})
endif ()
target_link_libraries(tests coverage_config)
target_link_libraries(tests sfml-graphics sfml-audio sfml-window sfml-network sfml-system ecs)

add_test(NAME exec_tests COMMAND tests --success)
