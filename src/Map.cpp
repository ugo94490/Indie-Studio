/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** map
*/

#include "Map.hpp"

Map::Map(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    loadMap(smgr, driver);
}

scene::IAnimatedMeshSceneNode * Map::createObject(float posx, float posy, char c, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    scene::IAnimatedMesh* mesh = smgr->getMesh("assets/textures/Block/ghost.obj");

    if (c == 'X') {
        scene::IAnimatedMeshSceneNode *model = smgr->addAnimatedMeshSceneNode(mesh);
        model->setPosition(irr::core::vector3df(posx, 8, posy));
        model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->setMaterialTexture(0, driver->getTexture("assets/textures/Block/bedrock.png"));
        return model;
    }
    if (c == 'O') {
        scene::IAnimatedMeshSceneNode *model = smgr->addAnimatedMeshSceneNode(mesh);
        model->setPosition(irr::core::vector3df(posx, 8, posy));
        model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->setMaterialTexture(0, driver->getTexture("assets/textures/Block/gold_block.png"));
        return model;
    }
    if (c == ' ') {
        scene::IAnimatedMeshSceneNode *model = smgr->addAnimatedMeshSceneNode(mesh);
        model->setPosition(irr::core::vector3df(posx, 0, posy));
        model->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        model->setMaterialTexture(0, driver->getTexture("assets/textures/Block/iron_block.png"));
        return model;
    }
    return NULL;
}


void Map::loadMap(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    std::string line;
    scene::IAnimatedMeshSceneNode *ptr;
    std::ifstream myfile ("assets/map/random_map.txt");

    if (!myfile.is_open())
        std::cout << ("Could not open map"); // a fix
    for (int i = 0; !myfile.eof(); i++) {
        getline (myfile, line);
        for (int j = 0; line[j]; j++) {
            ptr = createObject(float(j) * 8.0, float(i) * 8.0, line[j], smgr, driver);
            if (ptr)
                _nodes.push_back(ptr);
        }
    }
    myfile.close();
}

void Map::displayMap(video::IVideoDriver* driver)
{

}

void Map::core()
{

}

Map::~Map()
{

}