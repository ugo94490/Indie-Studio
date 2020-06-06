/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Song
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "Exception.hpp"
#include <SFML/Audio.hpp>

class Sound
{
    public:
        static sf::Music *createMusic(std::string path);
        static void setVolume(sf::Music *music, int volume);
        static void setLoop(sf::Music *music);
        static void playMusic(sf::Music *music);
        static void stopMusic(sf::Music *music);
        static void destroyMusic(sf::Music *music);
};

#endif /* !SOUND_HPP_ */
