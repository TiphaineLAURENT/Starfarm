//
// Created by TipLa on 13/04/2019.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <Entity.hpp>
#include <EntityManager.hpp>
#include <Component.hpp>
#include <ComponentManager.hpp>

class MyEntity : public ecs::Entity<MyEntity>
{
};

class MyComponent : public ecs::Component<MyComponent>
{
};

TEST_CASE("Entitity creation", "entity")
{
        auto entity = ecs::EntityManager::createEntity<MyEntity>();

        REQUIRE(entity.getEntityCount() == 1);
        REQUIRE(entity.getEntityID() == 0);
        REQUIRE(entity.getEntityTypeID() == 0);

        SECTION("Add component to entity") {
                auto component = entity.addComponent<MyComponent>();

                REQUIRE(component.getComponentCount() == 1);
                REQUIRE(component.getComponentID() == 0);
                REQUIRE(component.getComponentTypeID() == 0);

                REQUIRE(component.isActive() == true);

                REQUIRE(component.getOwner() == entity.getEntityID());
        }
}
