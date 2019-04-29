//
// Created by Tiphaine LAURENT on 29/04/2019.
//

#ifndef STARFARM_GAMEOBJECT_HPP
# define STARFARM_GAMEOBJECT_HPP

# include <ostream>
# include <Entity.hpp>

namespace game
{

  class TransformComponent;

  class GameObject : public ecs::Entity<GameObject>
  {
// ATTRIBUTES
  protected:
  public:
          TransformComponent *_transform = nullptr;

// METHODS:
  public: // CONSTRUCTORS
          GameObject();
          ~GameObject() override = default;
          GameObject(const GameObject &copy) = default;
          GameObject(GameObject &&other) noexcept = default;

  public: // OPERATORS
          GameObject &operator=(const GameObject &other) = default;
          GameObject &operator=(GameObject &&other) = default;

  public:
          template <class M>
          M *addBehaviour()
          {
                  return addComponent<M>(this);
          }
  };

  std::ostream &operator<<(std::ostream &out, const GameObject &);

}

#endif //STARFARM_GAMEOBJECT_HPP
