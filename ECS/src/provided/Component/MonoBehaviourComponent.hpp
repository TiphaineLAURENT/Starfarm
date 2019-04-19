//
// Created by TipLa on 14/04/2019.
//

#ifndef STARFARM_MONOBEHAVIOURCOMPONENT_HPP
# define STARFARM_MONOBEHAVIOURCOMPONENT_HPP

# include <ostream>
# include <Component.hpp>

namespace ecs
{

class MonoBehaviourComponent : public Component<MonoBehaviourComponent>
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
		MonoBehaviourComponent()
			: Component()
		{
			awake();
		}
        ~MonoBehaviourComponent() override = default;
        MonoBehaviourComponent(const MonoBehaviourComponent &copy) = default;
        MonoBehaviourComponent(MonoBehaviourComponent &&other) noexcept = default;

public: // OPERATORS
        MonoBehaviourComponent &operator=(const MonoBehaviourComponent &other) = default;
        MonoBehaviourComponent &operator=(MonoBehaviourComponent &&other) = default;

public:
		virtual void awake() {};
		virtual void start() {};
		virtual void update() {};
		virtual void fixedUpdate() {};
		virtual void lateUpdate() {};
};

std::ostream &operator<<(std::ostream &out, const MonoBehaviourComponent &);

}

#endif //STARFARM_MONOBEHAVIOURCOMPONENT_HPP
