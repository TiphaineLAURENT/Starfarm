//
// Project Starfarm
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_FPSCOUNTER_HPP
# define STARFARM_FPSCOUNTER_HPP

# include <ostream>


class FPSCounter
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        FPSCounter() = default;
        ~FPSCounter() override = default;
        FPSCounter(const FPSCounter &copy) = default;
        FPSCounter(FPSCounter &&other) noexcept = default;

public: // OPERATORS
        FPSCounter &operator=(const FPSCounter &other) = default;
        FPSCounter &operator=(FPSCounter &&other) = default;

public:
};

std::ostream &operator<<(std::ostream &out, const FPSCounter &);

#endif //STARFARM_FPSCOUNTER_HPP
