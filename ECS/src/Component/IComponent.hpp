/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** IComponent
*/

#ifndef ECS_ICOMPONENT_HPP
# define ECS_ICOMPONENT_HPP

# include <ostream>
# include <vector>
# include "../util/util.hpp"

namespace ecs
{

  using ComponentID = util::ID;
  using ComponentTypeID = util::ID;

  class IComponent
  {
// ATTRIBUTES
  private:
          static const ComponentID INVALID_COMPONENT_ID = util::INVALID_ID;

          ComponentID _componentID = INVALID_COMPONENT_ID;

          static std::vector<ComponentID> _freeID;

          static ComponentID _componentCount;

          EntityID _owner = util::INVALID_ID;

          bool _active = true;

  public:

// METHODS
  public:// CONSTRUCTORS
          IComponent();
          virtual ~IComponent();
          IComponent(const IComponent &copy) = default;
          IComponent(IComponent &&) noexcept = default;

  public: //OPERATORS
          IComponent &operator=(const IComponent &other) = default;
          IComponent &operator=(IComponent &&) = default;

  public:
          static const ComponentID getComponentCount();

          const ComponentID getComponentID() const;
          virtual const ComponentTypeID getComponentTypeID() const = 0;

          IComponent &setOwner(EntityID entityID);
          const EntityID getOwner() const;

          IComponent &setActive(bool state);
          const bool isActive() const;

  private:
  };

  std::ostream &operator<<(std::ostream &out, const IComponent *);

}

#endif /* !ECS_ICOMPONENT_HPP */
