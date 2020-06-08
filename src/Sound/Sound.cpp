/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Sound
*/

#include <iostream>
#include "Sound.hpp"

sf::Music *Sound::createMusic(std::string path)
{
    sf::Music *music = new sf::Music;

    if (!(*music).openFromFile(path))
        throw(Exception("Can't load music\n"));
    return (music);
}

void Sound::setVolume(sf::Music *music, int volume)
{
    music->setVolume(volume);
}

void Sound::setLoop(sf::Music *music)
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
    music->~Music();
}