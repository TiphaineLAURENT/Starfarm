/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** IEntityContainer
*/

#ifndef ECS_IENTITYCONTAINER_HPP
# define ECS_IENTITYCONTAINER_HPP

# include <ostream>
# include "IEntity.hpp"

namespace ecs
{

  class IEntityContainer
  {
// ATTRIBUTES
  private:
  public:

// METHODS
  public:// CONSTRUCTORS
          IEntityContainer() = default;
          virtual ~IEntityContainer() = default;
          IEntityContainer(const IEntityContainer &copy) = delete;
          IEntityContainer(IEntityContainer &&) noexcept = delete;

  public: //OPERATORS
          IEntityContainer &operator=(const IEntityContainer &other) = delete;
          IEntityContainer &operator=(IEntityContainer &&) = delete;

  public:
          virtual const char *getEntityContainerTypeName() const = 0;

          virtual void destroyEntity(EntityID) = 0;

  private:
  };

  std::ostream &operator<<(std::ostream &out, const IEntityContainer &);

}

#endif /* !ECS_IENTITYCONTAINER_HPP */
