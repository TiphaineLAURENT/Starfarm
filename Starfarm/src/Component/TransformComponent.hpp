//
// Created by tiphaine on 07/04/19.
//

#ifndef STARFARM_TRANSFORMCOMPONENT_HPP
# define STARFARM_TRANSFORMCOMPONENT_HPP

# include <ostream>
# include <Component.hpp>

class TransformComponent : public ecs::Component<TransformComponent>
{
// ATTRIBUTES
private:
        std::pair<size_t, size_t> _position;
        std::pair<size_t, size_t> _rotation;
        std::pair<size_t, size_t> _scale;

public:

// METHODS:
public: // CONSTRUCTORS
        TransformComponent();
        ~TransformComponent() = default;
        TransformComponent(const TransformComponent &copy) = default;
        TransformComponent(TransformComponent &&other) noexcept = default;

public: // OPERATORS
        TransformComponent &operator=(const TransformComponent &other) = default;
        TransformComponent &operator=(TransformComponent &&other) = default;
};

std::ostream &operator<<(std::ostream &out, const TransformComponent &);

#endif //STARFARM_TRANSFORMCOMPONENT_HPP
