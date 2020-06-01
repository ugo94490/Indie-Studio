/*
** EPITECH PROJECT, 2020
** AObject.cpp
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

AObject::AObject(char c, float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    setType(c, posx, posy, smgr, driver);
}

AObject::ObjectType AObject::getType(void) const
{
    return (_type);
}

void AObject::setType(char c, float posx, float posy, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/Block/ghost.obj");

    if (c == 0) {
        _type = Wall;
        _node = smgr->addAnimatedMeshSceneNode(mesh);
        //_pos = irr::core::vector3df(posx, 8, posy);
        _pos = std::make_pair(posx, posy);
        _node->setPosition(irr::core::vector3df(posx, 8, posy));
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, driver->getTexture("assets/textures/Block/bedrock.png"));
    }
    if (c == 1) {
        _type = Floor;
        _node = smgr->addAnimatedMeshSceneNode(mesh);
        //_pos = irr::core::vector3df(posx, 8, posy);
        _pos = std::make_pair(posx, posy);
        _node->setPosition(irr::core::vector3df(posx, 0, posy));
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, driver->getTexture("assets/textures/Block/gold_block.png"));
    }
    if (c == 2) {
        _type = Obstacle;
        _node = smgr->addAnimatedMeshSceneNode(mesh);
        _pos = std::make_pair(posx, posy);
        //_pos = irr::core::vector3df(posx, 8, posy);
        _node->setPosition(irr::core::vector3df(posx, 8, posy));
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMaterialTexture(0, driver->getTexture("assets/textures/Block/iron_block.png"));
    }
}

std::pair<float, float> AObject::getPos(void) const
{
    return (_pos);
}