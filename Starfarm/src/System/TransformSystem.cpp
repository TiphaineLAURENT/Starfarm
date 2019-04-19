//
// Created by tiphaine on 07/04/19.
//

#include <ComponentManager.hpp>
#include <iostream>
#include "TransformSystem.hpp"
#include "../Component/TransformComponent.hpp"

namespace game
{

	void game::TransformSystem::update()
	{
		for (auto& component : ecs::ComponentManager::getComponentContainer<TransformComponent>())
			component->update();
	}

}
