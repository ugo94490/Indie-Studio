/*
** EPITECH PROJECT, 2020
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"

Misc::Misc()
{
    device = irr::createDevice( irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
}

Misc::~Misc()
{
}

void Misc::loop()
{
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", irr::core::rect<irr::s32>(10,10,260,22), true);
	irr::scene::IAnimatedMesh* mesh = smgr->getMesh("assets/sydney.md2");
	if (!mesh) {
		device->drop();
		throw(Exception ("Mesh don't load"));
	}
	node = smgr->addAnimatedMeshSceneNode(mesh);
	if (node) {
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMD2Animation(irr::scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture("assets/sydney.bmp") );
	}
	smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));
	while(device->run()) {
		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();		
    }
	device->drop();
}