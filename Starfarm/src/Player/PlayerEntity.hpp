//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_PLAYERENTITY_HPP
# define STARFARM_PLAYERENTITY_HPP

# include <Entity.hpp>

# include "../Component/TransformComponent.hpp"
# include "../Component/RendererComponent.hpp"

namespace game
{

  class PlayerEntity : public ecs::Entity<PlayerEntity> {
  public:
          PlayerEntity()
          {
                  addComponent<TransformComponent>();
				  addComponent<RendererComponent>();
          }
  };

}

#endif //STARFARM_PLAYERENTITY_HPP
