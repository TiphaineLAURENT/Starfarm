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
	  IEntityContainer(const IEntityContainer &copy) = default;
	  IEntityContainer(IEntityContainer &&) noexcept = default;

    public: //OPERATORS
	  IEntityContainer &operator=(const IEntityContainer &other) = default;
	  IEntityContainer &operator=(IEntityContainer &&) = default;

    public:
	  virtual const char* getEntityContainerTypeName() const = 0;

	  virtual void destroyEntity(IEntity* object) = 0;

    private:
  };

  std::ostream &operator<<(std::ostream &out, const IEntityContainer &);

}

#endif /* !ECS_IENTITYCONTAINER_HPP */
