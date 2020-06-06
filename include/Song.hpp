/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Song
*/

#ifndef SONG_HPP_
#define SONG_HPP_

/* #include "Exception.hpp" */
#include <SFML/Audio.hpp>

class Song {
    public:
        Song();
        void explodeBombe();
        void setVolumeMusic(int volume);
        void setVolumeEffects(int volume);
        void playGameMusic();
        void playMenuMusic();
        void stopGameMusic();
        void stopMenuMusic();
        ~Song();

    private:
        sf::Music _musicMenu;
        sf::Music _musicGame;
        sf::Music _explode;
};

#endif /* !SONG_HPP_ */
