//
// Project Starfarm
// Created by Tiphaine LAURENT on 30/04/2019.
//

#include "FpsCounter.hpp"
#include "../../Component/TextComponent.hpp"
#include "../../RessourceManager.hpp"
#include "FpsCounterBehaviour.hpp"


namespace game
{

  FPSCounter::FPSCounter()
  {
        addComponent<TextComponent>("FPS: ",
                RessourceManager::getFont("Independent Modern 8x16.ttf"));
        addBehaviour<FPSCounterBehaviour>();
  }

}
