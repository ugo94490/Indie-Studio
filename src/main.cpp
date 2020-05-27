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

using namespace irr;
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

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
    Map mapBomber(driver);
    driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
    while(device->run() && driver)
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(0,0,0,0));
            mapBomber.displayMap();
            driver->endScene();
        }
    }
    device->drop();
    return 0;
}