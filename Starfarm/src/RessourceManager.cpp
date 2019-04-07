/*
** EPITECH PROJECT, 2021
** rtype
** File description:
** RessourceManager
*/

#include "RessourceManager.hpp"

namespace game
{

  RessourceManager *RessourceManager::_manager = nullptr;

  const sf::Texture &RessourceManager::getTexture(const std::string
                                                  &textureName,
                                                  const std::string &path)
  {
	  if (!_manager)
	  	_manager = new RessourceManager;

	  if (!_manager->_textures.count(textureName)) {
		  sf::Texture texture;
		  texture.loadFromFile(path + textureName);
		  _manager->_textures[textureName] =
			  std::make_unique<sf::Texture>(texture);
	  }

	  return *_manager->_textures[textureName];
  }

  sf::Music &RessourceManager::getMusic(const std::string &musicName,
                                              const std::string &path)
  {
	  if (!_manager)
		  _manager = new RessourceManager;

	  if (!_manager->_musics.count(musicName)) {
		  auto music = std::make_unique<sf::Music>();
		  music->openFromFile(path + musicName);
		  _manager->_musics[musicName] = std::move(music);
	  }

	  return *_manager->_musics[musicName];
  }

  const sf::Font &RessourceManager::getFont(const std::string &fontName,
                                            const std::string &path)
  {
	  if (!_manager)
		  _manager = new RessourceManager;

	  if (!_manager->_fonts.count(fontName)) {
		  sf::Font font;
		  font.loadFromFile(path + fontName);
		  _manager->_fonts[fontName] =
			  std::make_unique<sf::Font>(font);
	  }

	  return *_manager->_fonts[fontName];
  }

  const sf::SoundBuffer &RessourceManager::getSoundBuffer(const std::string
                                                          &soundBufferName,
                                                          const std::string &path)
  {
  	if (!_manager)
  		_manager = new RessourceManager;

  	if (_manager->_soundBuffers.count(soundBufferName)) {
	        sf::SoundBuffer buffer;
	        buffer.loadFromFile(path + soundBufferName);
	        _manager->_soundBuffers[soundBufferName] =
		        std::make_unique<sf::SoundBuffer>(buffer);
  	}

  	return *_manager->_soundBuffers[soundBufferName];
  }

  void RessourceManager::destroy()
  {
	  delete _manager;
  }

}
