/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Sound
*/

#include <iostream>
#include "Sound.hpp"

sf::Music *createMusic(std::string path)
{
    sf::Music *music = new sf::Music;

    if (!(*music).openFromFile(path))
        throw(Exception("Can't load explosion.wav\n"));
    return (music);
}

void Sound::setVolume(sf::Music *music, int volume)
{
    music->setVolume(volume);
}

void setLoop(sf::Music *music)
{
    music->setLoop(true);
}

void Sound::playMusic(sf::Music *music)
{
    music->play();
}

void Sound::stopMusic(sf::Music *music)
{
    music->stop();
}

void Sound::destroyMusic(sf::Music *music)
{
    delete music;
}