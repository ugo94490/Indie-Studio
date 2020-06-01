/*
** EPITECH PROJECT, 2020
** Floor.cpp
** File description:
** Floor.cpp
*/

#include "Floor.hpp"

Floor::Floor(float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/Block/ghost.obj");
    _type = ObjectType::Floor;
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    //_pos = irr::core::vector3df(posx, 8, posy);
    _pos = {posx, 0, posy};
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, driver->getTexture("assets/textures/Block/gold_block.png"));
}

Floor::~Floor()
{
}