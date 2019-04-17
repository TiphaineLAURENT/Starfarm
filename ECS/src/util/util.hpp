/*
** EPITECH PROJECT, 2021
** ECS
** File description:
** util
*/

#ifndef ECS_UTIL_HPP
# define ECS_UTIL_HPP

# include <cstddef>
# include <limits>
# include <iostream>

namespace ecs
{
  namespace util
  {

    using ID = size_t;
    static constexpr ID INVALID_ID = std::numeric_limits<ID>::max();

    template <class T>
    class FamilyTypeID
    {
    private:
            static ID _countID;

    public:
            template <class E>
            static const ID getTypeID()
            {
                    static const ID _typeID{_countID++};
                    return _typeID;
            }

            static const ID getCountID()
            {
                    return _countID;
            }
    };

    template <class T>
    size_t FamilyTypeID<T>::_countID = 0;

  }

  using EntityID = util::ID;

}

#endif //ECS_UTIL_HPP
