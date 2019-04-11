//
// Created by tiphaine on 11/04/19.
//

#ifndef STARFARM_RENDERERSYSTEM_HPP
# define STARFARM_RENDERERSYSTEM_HPP

# include <ostream>

class RendererSystem
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        RendererSystem();
        ~RendererSystem() = default;
        RendererSystem(const RendererSystem &copy) = default;
        RendererSystem(RendererSystem &&other) noexcept = default;

public: // OPERATORS
        RendererSystem &operator=(const RendererSystem &other) = default;
        RendererSystem &operator=(RendererSystem &&other) = default;
};

std::ostream &operator<<(std::ostream &out, const RendererSystem &);

#endif //STARFARM_RENDERERSYSTEM_HPP
