//
// Project Starfarm
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_SPRITECOMPONENT_HPP
# define STARFARM_SPRITECOMPONENT_HPP

# include <ostream>


class SpriteComponent
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        SpriteComponent() = default;
        ~SpriteComponent() override = default;
        SpriteComponent(const SpriteComponent &copy) = default;
        SpriteComponent(SpriteComponent &&other) noexcept = default;

public: // OPERATORS
        SpriteComponent &operator=(const SpriteComponent &other) = default;
        SpriteComponent &operator=(SpriteComponent &&other) = default;

public:
};

std::ostream &operator<<(std::ostream &out, const SpriteComponent &);

#endif //STARFARM_SPRITECOMPONENT_HPP
