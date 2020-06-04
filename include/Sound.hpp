/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Song
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

/* #include "Exception.hpp" */
#include <SFML/Audio.hpp>

class Sound {
    public:
        Sound();
        void explodeBombe();
        void setVolumeMusic(int volume);
        void setVolumeEffects(int volume);
        void playGameMusic();
        void playMenuMusic();
        void stopGameMusic();
        void stopMenuMusic();
        ~Sound();

    private:
        sf::Music _musicMenu;
        sf::Music _musicGame;
        sf::Music _explode;
};

#endif /* !SOUND_HPP_ */
