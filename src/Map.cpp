/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* wall = smgr->getMesh("assets/textures/Brick Block.3ds");
    scene::IAnimatedMesh* floor = smgr->getMesh("assets/textures/Block/ghost.obj");
    scene::IAnimatedMesh* obstacle = smgr->getMesh("assets/textures/Block/hatenablock.obj");
    _Wall = smgr->addAnimatedMeshSceneNode(wall);
    _Floor = smgr->addAnimatedMeshSceneNode(floor);
    _Obstacle = smgr->addAnimatedMeshSceneNode(obstacle);

    _Wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _Wall->setMD2Animation(scene::EMAT_STAND);
    _Wall->setMaterialTexture( 0, driver->getTexture("assets/textures/brick.png") );

    _Floor->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _Floor->setMD2Animation(scene::EMAT_STAND);
    _Floor->setMaterialTexture( 0, driver->getTexture("assets/textures/Block/hatenablock_nom.png") );

    _Obstacle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _Obstacle->setMD2Animation(scene::EMAT_STAND);
    _Obstacle->setMaterialTexture( 0, driver->getTexture("assets/textures/Block/hatenablock_nom.png") );
    loadMap();
}

std::shared_ptr<AObject> Map::createObject(float posx, float posy, char c) const
{
    if (c == 'X') {
        std::shared_ptr<AObject> ptr(new AObject(0, std::pair(posy, posx)));
        return ptr;
    }
    if (c == 'O') {
        std::shared_ptr<AObject> ptr(new AObject(1, std::pair(posy, posx)));
        return ptr;
    }
    if (c == ' ') {
        std::shared_ptr<AObject> ptr(new AObject(2, std::pair(posy, posx)));
        return ptr;
    }
    return NULL;
}

void Map::loadMap()
{
    std::string line;
    std::shared_ptr<AObject> ptr;
    std::ifstream myfile ("assets/map/random_map.txt");


    if (!myfile.is_open())
        std::cout << ("Could not open map"); // a fix
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++) {
            ptr = createObject(float(j) * 150.0, float(i) * 150.0, line[j]);
            if (ptr)
                _list.push_front(ptr);
        }
    }
    myfile.close();
}

void Map::displayMap(video::IVideoDriver* driver)
{
    std::pair<float, float> pos;

    for (auto it = _list.begin(); it != _list.end(); ++it) {
        pos = it->get()->getPos();
        if (it->get()->getType() == AObject::Wall)
            _Wall->setPosition(core::vector3df(pos.first, pos.second, 0));
        if (it->get()->getType() == AObject::Floor)
            _Floor->setPosition(core::vector3df(pos.first, pos.second, 0));
        if (it->get()->getType() == AObject::Obstacle)
            _Obstacle->setPosition(core::vector3df(pos.first, pos.second, 0));
    }
}

void Map::core()
{

}

Map::~Map()
{

}