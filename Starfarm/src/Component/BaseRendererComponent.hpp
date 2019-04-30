//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_BASERENDERERCOMPONENT_HPP
# define STARFARM_BASERENDERERCOMPONENT_HPP

# include <ostream>


class BaseRendererComponent
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        BaseRendererComponent() = default;
        ~BaseRendererComponent() override = default;
        BaseRendererComponent(const BaseRendererComponent &copy) = default;
        BaseRendererComponent(BaseRendererComponent &&other) noexcept = default;

public: // OPERATORS
        BaseRendererComponent &operator=(const BaseRendererComponent &other) = default;
        BaseRendererComponent &operator=(BaseRendererComponent &&other) = default;

public:
};

std::ostream &operator<<(std::ostream &out, const BaseRendererComponent &);

#endif //STARFARM_BASERENDERERCOMPONENT_HPP
