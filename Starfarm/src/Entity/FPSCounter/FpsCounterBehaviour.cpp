//
// Created by TipLa on 30/04/2019.
//

#include "FpsCounterBehaviour.hpp"
#include "../GameObject.hpp"
#include "../../Component/TextComponent.hpp"


namespace game
{

  FPSCounterBehaviour::FPSCounterBehaviour(GameObject *gameObject)
          : MonoBehaviourComponent(gameObject), _clock()
  {
  }

  void FPSCounterBehaviour::awake()
  {
          _text = _gameObject->getComponent<TextComponent>();
          _text->setPosition(100, 100);
  }

  void FPSCounterBehaviour::update()
  {
          auto elapsed = _clock.restart();
          _text->setString(std::to_string((int)(1 / elapsed.asSeconds())));
  }
}
