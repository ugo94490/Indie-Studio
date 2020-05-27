/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** main
*/

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

int main()
{
    // demande un pilote a l'utilisateur
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
        return 1;

    // crée le moteur

    IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(512, 384));

    if (device == 0)
        return 1; // on ne peut pas créer le pilote sélectionné.

    device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

    video::IVideoDriver* driver = device->getVideoDriver();
    video::ITexture* images = driver->getTexture("assets/textures/grass.png");
    driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;

    while(device->run() && driver)
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(0,0,0,0));
             // dessine le fond de monde feu et dragon.
            driver->draw2DImage(images, core::position2d<s32>(50,50),
                core::rect<s32>(0,0,32,32), 0,
                video::SColor(255,255,255,255), true);

            //driver->enableMaterial2D();
            /* core::position2d<s32> m = device->getCursorControl()->getPosition();
            driver->draw2DRectangle(video::SColor(100,255,255,255), core::rect<s32>(m.X-20, m.Y-20, m.X+20, m.Y+20)); */
            driver->endScene();
        }
    }
    device->drop();
    return 0;
}