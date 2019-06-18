//
// Project Starfarm
// Created by Tiphaine LAURENT on 18/06/2019.
//

#ifndef STARFARM_EVENTMANAGER_HPP
# define STARFARM_EVENTMANAGER_HPP

# include <ostream>


class EventManager
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
        EventManager() = default;
        ~EventManager() override = default;
        EventManager(const EventManager &copy) = default;
        EventManager(EventManager &&other) noexcept = default;

public: // OPERATORS
        EventManager &operator=(const EventManager &other) = default;
        EventManager &operator=(EventManager &&other) = default;

public:
};

std::ostream &operator<<(std::ostream &out, const EventManager &);

#endif //STARFARM_EVENTMANAGER_HPP
