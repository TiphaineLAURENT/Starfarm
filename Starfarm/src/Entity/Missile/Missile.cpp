//
// Project Starfarm
// Created by Tiphaine LAURENT on 02/05/2019.
//

#include "Missile.hpp"
#include "../../Component/SpriteComponent.hpp"
#include "../../RessourceManager.hpp"
#include "MissileBehaviour.hpp"


namespace game
{
  Missile::Missile()
  {
          addComponent<SpriteComponent>(
                  RessourceManager::getTexture
                          ("missile.png")
          );
          addBehaviour<MissileBehaviour>()->awake();
  }
}
