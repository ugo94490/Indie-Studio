/*
** EPITECH PROJECT, 2020
** Wall.cpp
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

Wall::Wall(float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/box.MD3");
    _type = ObjectType::Wall;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _pos = {posx, 40, posy};
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/brick.jpg"));
}

Wall::~Wall()
{
}