/*
** EPITECH PROJECT, 2020
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core()
{
    device = irr::createDevice( irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1024, 980), 16, false, false, false, 0);
    if (!device)
        throw(Exception ("Error window not open"));
    device->setWindowCaption(L"Indie Studio");
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
	loop();
}

Core::~Core()
{
}

void Core::loop()
{
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", irr::core::rect<irr::s32>(10,10,260,22), true);
	irr::scene::IAnimatedMesh* mesh = smgr->getMesh("assets/BOMB/dinamite.obj");
	if (!mesh) {
		device->drop();
		throw(Exception ("Mesh don't load"));
	}
	node = smgr->addAnimatedMeshSceneNode(mesh);
	if (node) {
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		node->setMD2Animation(irr::scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture("assets/BOMB/D.png") );
	}
	smgr->addCameraSceneNode(0, irr::core::vector3df(5, 9, -2), irr::core::vector3df(5,0,5), true);
	while(device->run()) {
		driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
    }
	device->drop();
}