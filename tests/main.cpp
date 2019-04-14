//
// Created by TipLa on 13/04/2019.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include <Entity.hpp>
#include <EntityManager.hpp>
#include <Component.hpp>
#include <ComponentManager.hpp>
#include <System.hpp>
#include <SystemManager.hpp>

class MyEntity : public ecs::Entity<MyEntity>
{
};

class MyComponent : public ecs::Component<MyComponent>
{
};

class MySystem : public ecs::System<MySystem>
{
};

TEST_CASE("Basic creation", "creation")
{
        auto entity = ecs::EntityManager::createEntity<MyEntity>();

        REQUIRE(entity.getEntityCount() == 1);
        REQUIRE(entity.getEntityID() == 0);
        REQUIRE(entity.getEntityTypeID() == 0);

        auto component = entity.addComponent<MyComponent>();

        REQUIRE(component.getComponentCount() == 1);
        REQUIRE(component.getComponentID() == 0);
        REQUIRE(component.getComponentTypeID() == 0);
        REQUIRE(component.isActive());
        REQUIRE(component.getOwner() == entity.getEntityID());

        auto &system = ecs::SystemManager::createSystem<MySystem>();

        REQUIRE(system.getPriority() == ecs::SystemPriority::NORMAL);
        REQUIRE(system.getSystemTypeID() == 0);
        REQUIRE(system.getUpdateInterval() == 1.);
        REQUIRE(system.isEnable());
}
