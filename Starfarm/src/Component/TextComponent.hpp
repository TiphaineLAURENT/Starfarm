//
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_TEXTCOMPONENT_HPP
# define STARFARM_TEXTCOMPONENT_HPP

# include <ostream>

namespace game
{

  class TextComponent
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          TextComponent() = default;
          ~TextComponent() override = default;
          TextComponent(const TextComponent &copy) = default;
          TextComponent(TextComponent &&other) noexcept = default;

  public: // OPERATORS
          TextComponent &operator=(const TextComponent &other) = default;
          TextComponent &operator=(TextComponent &&other) = default;

  public:
  };

  std::ostream &operator<<(std::ostream &out, const TextComponent &);

}

#endif //STARFARM_TEXTCOMPONENT_HPP
