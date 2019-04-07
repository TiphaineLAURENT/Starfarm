/*
** EPITECH PROJECT, 2021
** rtype
** File description:
** RessourceManager
*/

#ifndef RTYPE_RESSOURCEMANAGER_HPP
# define RTYPE_RESSOURCEMANAGER_HPP

#include <ostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace client
{

  class RessourceManager
  {
// ATTRIBUTES
    private:
	  static RessourceManager *_manager;
	  std::map<std::string, std::unique_ptr<sf::Texture>> _textures;
	  std::map<std::string, std::unique_ptr<sf::Music>> _musics;
	  std::map<std::string, std::unique_ptr<sf::Font>> _fonts;
	  std::map<std::string, std::unique_ptr<sf::SoundBuffer>> _soundBuffers;

    public:

// METHODS
    public:// CONSTRUCTORS
	  RessourceManager() = default;
	  ~RessourceManager() = default;
//	RessourceManager(const RessourceManager &copy) = default;
//	RessourceManager(RessourceManager &&) noexcept = default;

    public: //OPERATORS
//	RessourceManager &operator=(const RessourceManager &other) = default;
//	RessourceManager &operator=(RessourceManager &&) = default;

    public:
	  static const sf::Texture &getTexture(const std::string &textureName,
	                                       const std::string &path =
	                                       TEXTURE_DIRECTORY);
	  static sf::Music &getMusic(const std::string &musicName,
	                             const std::string &path =
                                     MUSIC_DIRECTORY);
	  static const sf::Font &getFont(const std::string &fontName,
                                         const std::string &path =
	                                 FONT_DIRECTORY);
	  static const sf::SoundBuffer &getSoundBuffer(const std::string
	                                               &soundBufferName,
                                                       const std::string
	                                               &path = SOUND_DIRECTORY);
	  static void destroy();

    private:
  };

  std::ostream &operator<<(std::ostream &out, const RessourceManager &);

}

#endif /* !RTYPE_RESSOURCEMANAGER_HPP */
