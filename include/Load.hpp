/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Load
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Exception.hpp"
#include "Player.hpp"
#include "Powerup.hpp"
#include "SolidWall.hpp"
#include "BreakableWall.hpp"
#include "Explosion.hpp"
#include "Bomb.hpp"
#include "Ground.hpp"

class PlayerLoad {
    public:
        PlayerLoad() : _name(""), _pos({0, BLOCK_SIZE, 0}), _skin(1),
        _id_bomber(0), _ia(true), _alive(0), _speedmul(3), _max_bombs(1),
        _planted(0), _power(2), _throughwall(0), _throughbomb(0),
        _bombpierce(0), _invincibletime(0), _score(0) {
            _bind.push_back(std::pair<bool, char>(false, -1));
            _bind.push_back(std::pair<bool, char>(false, -1));
            _bind.push_back(std::pair<bool, char>(false, -1));
            _bind.push_back(std::pair<bool, char>(false, -1));
            _bind.push_back(std::pair<bool, char>(false, -1));
        }
        ~PlayerLoad() = default;
        std::string _name;
        irr::core::vector3d<f32> _pos;
        int _skin;
        int _id_bomber;
        bool _ia;
        bool _alive;
        int _speedmul;
        int _max_bombs;
        int _planted;
        int _power;
        bool _throughwall;
        bool _throughbomb;
        bool _bombpierce;
        float _invincibletime;
        int _score;
        std::vector<std::pair<bool, char>> _bind;
};

class Load {
    public:
        Load(std::string const &filepath, Core *core);
        ~Load() = default;
        void readfile(std::string const &filepath);
        void check_line_base();
        void tryLoadPlayer();
        std::string loadName(std::vector<std::string> words);
        void tryLoadGround();
        void tryLoadSolidWall();
        void tryLoadBreakableWall();
        void tryLoadPowerup();
        void tryLoadBomb();
        void tryLoadExplosion();
        std::list<std::shared_ptr<GameObject>> getObjects() const;
        std::list<std::shared_ptr<Player>> getPlayers() const;
        static void loadFloatInto(std::string const &str, float &to_load);
        static void loadIntInto(std::string const &str, int &to_load);
        static void loadBoolInto(std::string const &str, bool &to_load);
        static void loadCharInto(std::string const &str, char &to_load);
        static std::vector<std::string> strToWords(std::string const &str);

    protected:
        std::list<std::shared_ptr<Player>> _players;
        std::list<std::shared_ptr<GameObject>> _objects;
        std::vector<std::string> _tab;
        size_t _idx;
        Core *_core;
    private:
};
