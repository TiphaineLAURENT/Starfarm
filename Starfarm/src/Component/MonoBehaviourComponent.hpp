//
// Created by TipLa on 14/04/2019.
//

#ifndef ECS_MONOBEHAVIOURCOMPONENT_HPP
# define ECS_MONOBEHAVIOURCOMPONENT_HPP

# include <ostream>
# include <Component.hpp>

namespace game
{
  class GameObject;

  class TransformComponent;

  class MonoBehaviourComponent : public ecs::Component<MonoBehaviourComponent>
  {
// ATTRIBUTES
  protected:
          GameObject *const _gameObject = nullptr;

          TransformComponent *const _transform = nullptr;

  public:

// METHODS:
  public: // CONSTRUCTORS
          explicit MonoBehaviourComponent(GameObject *gameObject);
          ~MonoBehaviourComponent() override = default;
          MonoBehaviourComponent(const MonoBehaviourComponent &copy) = default;
          MonoBehaviourComponent(MonoBehaviourComponent &&other) noexcept = default;

  public: // OPERATORS
          MonoBehaviourComponent &operator=(const MonoBehaviourComponent
                  &other) = delete;
          MonoBehaviourComponent &operator=(MonoBehaviourComponent &&other) =
                  delete;

  public:
          virtual void awake()
          {
          };
          virtual void start()
          {
          };
          virtual void update()
          {
          };
          virtual void fixedUpdate()
          {
          };
          virtual void lateUpdate()
          {
          };
  };

  std::ostream &operator<<(std::ostream &out, const MonoBehaviourComponent &);

}

#endif //ECS_MONOBEHAVIOURCOMPONENT_HPP
