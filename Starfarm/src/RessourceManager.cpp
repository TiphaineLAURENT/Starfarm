/*
** EPITECH PROJECT, 2021
** rtype
** File description:
** RessourceManager
*/

#include <iostream>
#include "RessourceManager.hpp"

namespace game
{

  RessourceManager *RessourceManager::_manager = nullptr;

  const sf::Texture &RessourceManager::getTexture(const std::string
                                                  &textureName,
                                                  const std::string &path)
  {
          RessourceManager &manager = getInstance();

	  if (!manager._textures.count(textureName)) {
		  sf::Texture texture;
		  texture.loadFromFile(path + textureName);
		  manager._textures[textureName] =
			  std::make_unique<sf::Texture>(texture);
	  }

	  return *manager._textures[textureName];
  }

  sf::Music &RessourceManager::getMusic(const std::string &musicName,
                                              const std::string &path)
  {
          RessourceManager &manager = getInstance();

	  if (!manager._musics.count(musicName)) {
		  auto music = std::make_unique<sf::Music>();
		  music->openFromFile(path + musicName);
		  manager._musics[musicName] = std::move(music);
	  }

	  return *manager._musics[musicName];
  }

  const sf::Font &RessourceManager::getFont(const std::string &fontName,
                                            const std::string &path)
  {
          RessourceManager &manager = getInstance();

	  if (!manager._fonts.count(fontName)) {
		  sf::Font font;
		  font.loadFromFile(path + fontName);
		  manager._fonts[fontName] =
			  std::make_unique<sf::Font>(font);
	  }

	  return *manager._fonts[fontName];
  }

  const sf::SoundBuffer &RessourceManager::getSoundBuffer(const std::string
                                                          &soundBufferName,
                                                          const std::string &path)
  {
          RessourceManager &manager = getInstance();

  	if (manager._soundBuffers.count(soundBufferName)) {
	        sf::SoundBuffer buffer;
	        buffer.loadFromFile(path + soundBufferName);
	        manager._soundBuffers[soundBufferName] =
		        std::make_unique<sf::SoundBuffer>(buffer);
  	}

  	return *manager._soundBuffers[soundBufferName];
  }

  void RessourceManager::destroy()
  {
	  delete _manager;
  }

  RessourceManager &RessourceManager::getInstance()
  {
          if (!_manager)
                  _manager = new RessourceManager;
          return *_manager;
  }

}
