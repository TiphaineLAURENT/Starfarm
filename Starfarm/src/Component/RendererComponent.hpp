//
// Created by tiphaine on 11/04/19.
//

#ifndef STARFARM_RENDERERCOMPONENT_HPP
# define STARFARM_RENDERERCOMPONENT_HPP

# include <ostream>

class RendererComponent
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        RendererComponent();
        ~RendererComponent() = default;
        RendererComponent(const RendererComponent &copy) = default;
        RendererComponent(RendererComponent &&other) noexcept = default;

public: // OPERATORS
        RendererComponent &operator=(const RendererComponent &other) = default;
        RendererComponent &operator=(RendererComponent &&other) = default;
};

std::ostream &operator<<(std::ostream &out, const RendererComponent &);

#endif //STARFARM_RENDERERCOMPONENT_HPP
