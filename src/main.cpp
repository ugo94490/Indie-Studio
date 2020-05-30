/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** main
*/

#include <iostream>
#include "Map.hpp"
#include "Core.hpp"
#include "Exception.hpp"
#include "GeneratorMap.hpp"

int main()
{
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
        return 1;
    IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(1280, 720));
    if (device == 0)
        return 1;
    device->setWindowCaption(L"Bomberman");
    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    GeneratorMap gene(17, 17);
    Map mapBomber(smgr, driver);
    driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
    smgr->addCameraSceneNode(0, irr::core::vector3df(-20,150,-20), irr::core::vector3df(104,0,136));
    while(device->run() && driver)
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(0,0,0,0));
            smgr->drawAll();
            driver->endScene();
        }
    }
    device->drop();
    return 0;
}