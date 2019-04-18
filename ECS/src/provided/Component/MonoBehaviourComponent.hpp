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
        MonoBehaviourComponent() = default;
        ~MonoBehaviourComponent() override = default;
        MonoBehaviourComponent(const MonoBehaviourComponent &copy) = default;
        MonoBehaviourComponent(MonoBehaviourComponent &&other) noexcept = default;

public: // OPERATORS
        MonoBehaviourComponent &operator=(const MonoBehaviourComponent &other) = default;
        MonoBehaviourComponent &operator=(MonoBehaviourComponent &&other) = default;

public:
		virtual void Start() {};
		virtual void Update() {};
		virtual void FixedUpdate() {};
		virtual void LateUpdate() {};
		virtual void OnGUI() {};
		virtual void OnDisable() {};
		virtual void OnEnable() {};
};

std::ostream &operator<<(std::ostream &out, const MonoBehaviourComponent &);

}

#endif //STARFARM_MONOBEHAVIOURCOMPONENT_HPP
