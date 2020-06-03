/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Sound
*/

#include <iostream>
#include "Sound.hpp"

Sound::Sound()
{
    sf::SoundBuffer buffer;

    if (!_explode.openFromFile("explosion.wav"))
        throw(Exception("Can't load explosion.wav\n"));
    if (!_musicGame.openFromFile("fight.ogg"))
        throw(Exception("Can't load explosion.wav\n"));
}

void Sound::setVolumeMusic(int volume)
{
    _musicMenu.setVolume(volume);
    _musicGame.setVolume(volume);
}

void Sound::setVolumeEffects(int volume)
{
    _explode.setVolume(volume);
}

void Sound::playGameMusic()
{
    _musicGame.play();
    _musicGame.setLoop(true);
}

void Sound::playMenuMusic()
{
    _musicMenu.play();
    _musicMenu.setLoop(true);
}

void Sound::stopGameMusic()
{
    _musicGame.stop();
}

void Sound::stopMenuMusic()
{
    _musicMenu.stop();
}

void Sound::explodeBombe()
{
    _explode.play();
}

Sound::~Sound()
{
}