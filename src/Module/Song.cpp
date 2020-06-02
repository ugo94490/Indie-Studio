/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Song
*/

#include <iostream>
#include "Song.hpp"

Song::Song()
{
    sf::SoundBuffer buffer;

    if (!_explode.openFromFile("explosion.wav"))
        throw(Exception("Can't load explosion.wav\n"));
    if (!_musicGame.openFromFile("fight.ogg"))
        throw(Exception("Can't load explosion.wav\n"));
}

void Song::setVolumeMusic(int volume)
{
    _musicMenu.setVolume(volume);
    _musicGame.setVolume(volume);
}

void Song::setVolumeEffects(int volume)
{
    _explode.setVolume(volume);
}

void Song::playGameMusic()
{
    _musicGame.play();
    _musicGame.setLoop(true);
}

void Song::playMenuMusic()
{
    _musicMenu.play();
    _musicMenu.setLoop(true);
}

void Song::stopGameMusic()
{
    _musicGame.stop();
}

void Song::stopMenuMusic()
{
    _musicMenu.stop();
}

void Song::explodeBombe()
{
    _explode.play();
}

Song::~Song()
{
}