//
// Created by TipLa on 14/04/2019.
//

#ifndef STARFARM_PLAYERBEHAVIOUR_HPP
# define STARFARM_PLAYERBEHAVIOUR_HPP

# include <ostream>
# include <Component/MonoBehaviourComponent.hpp>

namespace ecs
{

class PlayerBehaviour : public MonoBehaviourComponent
{
// ATTRIBUTES
private:
public:

// METHODS:
public: // CONSTRUCTORS
		PlayerBehaviour() = default;
        ~PlayerBehaviour() override = default;
		PlayerBehaviour(const PlayerBehaviour&copy) = default;
		PlayerBehaviour(PlayerBehaviour&&other) noexcept = default;

public: // OPERATORS
		PlayerBehaviour&operator=(const PlayerBehaviour&other) = default;
		PlayerBehaviour&operator=(PlayerBehaviour&&other) = default;

public:
		virtual void Start() {};
		virtual void Update() {};
		virtual void FixedUpdate() {};
		virtual void LateUpdate() {};
		virtual void OnGUI() {};
		virtual void OnDisable() {};
		virtual void OnEnable() {};
};

std::ostream &operator<<(std::ostream &out, const PlayerBehaviour&);

}

#endif //STARFARM_PLAYERBEHAVIOUR_HPP
