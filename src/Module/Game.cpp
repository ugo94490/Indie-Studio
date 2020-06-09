/*
** EPITECH PROJECT, 2020
** Game.cpp
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "Factory.hpp"
#include "Rect.hpp"

Game::Game(Core *obj)
{
    core = obj;
}

std::shared_ptr<Player> Game::getPlayerInput(char c)
{
    for (size_t i = 0; i < character.size(); i++)
        for (size_t j = 0; j < character[i]->_bind.size(); j++)
            if (character[i]->_bind[j].second == c)
                return (character[i]);
    return (nullptr);
}

void Game::assignPlayerPos()
{
    int i = 0;

    for (auto it = _players.begin(); it != _players.end() && i < 4; ++it, i++) {
        if (i == 0)
            (*it)->setPos({BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE});
        if (i == 1)
            (*it)->setPos({BLOCK_SIZE * 15, BLOCK_SIZE, BLOCK_SIZE * 15});
        if (i == 2)
            (*it)->setPos({BLOCK_SIZE * 15, BLOCK_SIZE, BLOCK_SIZE});
        if (i == 3)
            (*it)->setPos({BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE * 15});
    }
}

void Game::getInput()
{
    for (auto it = _players.begin(); it != _players.end(); ++it)
        (*it)->handle_input(core);
}

void Game::removeDead()
{
    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        if ((*it)->do_remove()) {
            GameObject::removeObj(_objects, (*it));
            it = _objects.begin();
        }
    }
}

bool Game::check_end()
{
    int nb_alive = 0;

    for (auto it = _players.begin(); it != _players.end(); ++it)
        if (!(*it)->do_remove())
            nb_alive += 1;
    if (nb_alive > 1)
        return (false);
    return (true);
}

void Game::Loop(std::vector<std::shared_ptr<IModule>> obj)
{
    tab = obj;
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
    scene::ISceneNode *skybox = core->smgr->addSkyBoxSceneNode(
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_up.jpg"),
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_dn.jpg"),
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_rt.jpg"),
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_lf.jpg"),
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_ft.jpg"),
        Factory::Check_load(core->driver, "./assets/textures/skybox/browncloud_bk.jpg"));
    (void)skybox;
    core->driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, true);
    Map mapBomber(core->smgr, core->driver);
    core->driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
    core->driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;
    core->smgr->addCameraSceneNode(0, irr::core::vector3df(340,700,160), irr::core::vector3df(340,0,340));

    std::chrono::steady_clock::time_point _start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point _end = std::chrono::steady_clock::now();
    float timepassed;
    _objects = mapBomber.getMap();
    for (auto it = tab[1]->character.begin(); it != tab[1]->character.end(); ++it) {
        _players.push_back(*it);
        _objects.push_back(*it);
    }
    assignPlayerPos();
    while(core->device->run() && core->driver && !check_end()) {
        _end = std::chrono::steady_clock::now();
        timepassed = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
        _start = std::chrono::steady_clock::now();
        getInput();
        if (core->recv->eve.EventType == irr::EET_KEY_INPUT_EVENT && core->recv->eve.KeyInput.PressedDown == true
            && core->recv->eve.KeyInput.Char == 27) {
            Pause();
            _end = std::chrono::steady_clock::now();
            _start = std::chrono::steady_clock::now();
        }
        for (auto it = _objects.begin(); it != _objects.end(); ++it)
            (*it)->update(_objects, timepassed);
        removeDead();
        if (core->device->isWindowActive()) {
            core->driver->beginScene(true, true, video::SColor(0,0,0,0));
            core->smgr->drawAll();
            core->driver->endScene();
        }
    }
}

void Game::Pause()
{
    while(core->device->run()) {
        if (core->device->isWindowActive()) {
            core->driver->beginScene(true, true, video::SColor(0,0,0,0));
            core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
            Factory::Button(core, tab[3], irr::core::position2d<irr::s32>(760, 454), options_rect);
            if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), back_rect) == true)
                break;
            if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(120, 300), name_rect))
                std::cout << "SAVE 1" << std::endl;
            if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 300), name_rect))
                std::cout << "SAVE 2" << std::endl;
            if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(1400, 300), name_rect))
                std::cout << "SAVE 3" << std::endl;
            core->font->draw(L"SAVE 1", irr::core::rect<irr::s32>(120, 300, 520, 400), irr::video::SColor(255,0,0,0), true, true);
            core->font->draw(L"SAVE 2", irr::core::rect<irr::s32>(760, 300, 1160, 400), irr::video::SColor(255,0,0,0), true, true);
            core->font->draw(L"SAVE 3", irr::core::rect<irr::s32>(1400, 300, 1800, 400), irr::video::SColor(255,0,0,0), true, true);
            core->driver->endScene();
        }
    }
}

Game::~Game()
{
}