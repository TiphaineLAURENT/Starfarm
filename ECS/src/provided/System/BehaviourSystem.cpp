//
// Created by tiphaine on 11/04/19.
//

#include "BehaviourSystem.hpp"
#include "MonoBehaviourComponent.hpp"
#include "ComponentManager.hpp"

namespace ecs
{
	BehaviourSystem::BehaviourSystem()
	{
		for (auto& behaviour : ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
			behaviour->awake();
		}
	}

	void BehaviourSystem::start()
	{
		for (auto& behaviour : ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
			behaviour->start();
		}
	}

	void ecs::BehaviourSystem::update()
		: System()
	{
		for (auto& behaviour : ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
			behaviour->update();
		}
		for (auto& behaviour : ComponentManager::getComponentContainer<MonoBehaviourComponent>()) {
			behaviour->lateUpdate();
		}
	}
}