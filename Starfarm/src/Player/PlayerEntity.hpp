//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_PLAYERENTITY_HPP
# define STARFARM_PLAYERENTITY_HPP

# include "../Entity/GameObject.hpp"
# include "PlayerBehaviour.hpp"
# include "../RessourceManager.hpp"
# include "../Component/SpriteComponent.hpp"


namespace game
{

  class PlayerEntity : public GameObject
  {
  public:
          PlayerEntity()
                  : GameObject()
          {
                  auto renderer = addComponent<SpriteComponent>(
                          RessourceManager::getTexture(
                                  "darkgrey_05.png"
                          ));
                  addBehaviour<PlayerBehaviour>();
          }

          ~PlayerEntity() override = default;
  };

}

#endif //STARFARM_PLAYERENTITY_HPP
