/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#pragma once

#include "Bomb.hpp"
class Core;

class Player : public GameObject {
    public:
        Player(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia);
        Player(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver, std::string name, irr::video::ITexture *skin, int id, bool ia);
        ~Player();
        void update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed);
        irr::core::vector3d<f32> getPos() const;
        GameObject::ObjTypes getType() const;
        bool do_remove() const;
        scene::IAnimatedMeshSceneNode *getNode() const;
        void setNode(scene::IAnimatedMeshSceneNode *node);
        void handle_input(Core *core, std::list<std::shared_ptr<GameObject>> const &objs);
        void collide(std::list<std::shared_ptr<GameObject>> &objs);
        void collideWall();
        void collidePowerUp(std::list<std::shared_ptr<GameObject>> &objs, std::shared_ptr<GameObject> powerup);
        void plantBomb(std::list<std::shared_ptr<GameObject>> &objs);
        int getPlanted() const;
        void setPlanted(int planted);
        int getPower() const;
        bool getPierce() const;
        void setAnim();
        void setBind(std::vector<std::pair<bool, char>> bind);
        void setPos(irr::core::vector3d<f32> pos);
        void setScore(int score);
        int getScore(void) const;
        std::string getName();
        void ComputeIA(std::list<std::shared_ptr<GameObject>> const &objs);
        int IADodge(int posx, int posz, std::vector<std::vector<char>> tab);
        void IAAtk(int posx, int posz, std::vector<std::vector<char>> const &tab);
        std::vector<std::vector<char>> simulatePlant(int posx, int posz, std::vector<std::vector<char>> const &vec);
        std::vector<std::vector<char>> getTabDanger(std::list<std::shared_ptr<GameObject>> const &objs);
        void setBomberId(int id);
        int getBomberId() const;
        void save(std::ofstream &stream);
        friend std::ostream &operator<<(std::ostream &os, Player const &player);

        std::vector<std::pair<bool, char>> _bind;

    protected:
    private:
        scene::IAnimatedMesh* _meshIdle;
        scene::IAnimatedMesh* _meshMove;
        std::string _name;
        irr::video::ITexture *_skin;
        scene::IAnimatedMeshSceneNode *_node;
        scene::ISceneManager* _smgr;
        video::IVideoDriver* _driver;
        irr::core::vector3d<f32> _pos;
        irr::core::vector3d<f32> _speed;
        bool _ia;
        bool _alive;
        bool _planting;
        int _speedmul;
        int _max_bombs;
        int _planted;
        int _power;
        bool _throughwall;
        bool _throughbomb;
        bool _bombpierce;
        float _invincbletime;
        float _buffscore;
        int _score;
        bool _do_anim;
        int _id;
        float _timepassed;
        int _idx_chara;
        int _id_bomber;
};

#include "Core.hpp"