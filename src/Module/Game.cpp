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
        if (!(*it)->do_remove())
            (*it)->handle_input(core, _objects);
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
    for (auto it = _players.begin(); it != _players.end(); ++it)
        if (!(*it)->do_remove())
            (*it)->setScore((*it)->getScore() + 100);
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
    end();
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

std::pair<std::string, int> Game::getPlayerScore()
{
    std::pair<std::string, int> score;
    int max = -1;

    for (auto i = _players.begin(); i != _players.end(); i++)
        if (i->get()->getScore() > max)
            max = i->get()->getScore();
    for (auto i = _players.begin(); i != _players.end(); i++)
        if (i->get()->getScore() == max)
            score = std::make_pair(i->get()->getName(), i->get()->getScore());
    return (score);
}

bool Factory::num(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if ((str[i] > '9' || str[i] < '0') && str[i] != 0 && str[i] != '\n')
            return (false);
    return (true);
}

std::vector<std::pair<std::string, int>> Game::getScore(std::string path)
{
    std::fstream myfile(path);
    std::string line;
    std::vector<std::pair<std::string, int>> score;
    int offset = 0;
    std::string nb;

    score.erase(score.begin(), score.end());
    if (!myfile.is_open())
        throw(Exception("Can't open file"));
    for (int i = 0; !myfile.eof(); i++) {
        offset = -1;
        getline (myfile, line);
        offset = line.find(' ');
        if (offset == (int)line.size())
            continue;
        nb = line.substr(offset + 1);
        if (Factory::num(nb) == false || nb.size() == 0 || nb[0] == '\n')
            continue;
        score.push_back(std::make_pair(line.substr(0, offset), std::stoi(nb)));
    }
    return (score);
}

std::vector<std::pair<std::string, int>> Game::concat_score(std::vector<std::pair<std::string, int>> tab_score, std::pair<std::string, int> score)
{
    int idx = -1;
    std::vector<std::pair<std::string, int>> new_tab;

    for (size_t i = 0; i < tab_score.size(); i++) {
        if (score.second > tab_score[i].second)
            idx = i;
        if (idx != -1)
            break;
    }
    if (idx == -1) {
        if (tab_score.size() >= 9)
            return (tab_score);
        tab_score.push_back(score);
        return (tab_score);
    }
    for (size_t i = 0; i < tab_score.size(); i++) {
        if ((int)i == idx)
            new_tab.push_back(score);
        new_tab.push_back(tab_score[i]);
    }
    return (new_tab);
}

void Game::write_score(std::string path, std::vector<std::pair<std::string, int>> tab_score)
{
    std::ofstream ofs;
    ofs.open(path, std::ofstream::trunc | std::ofstream::out);

    for (size_t i = 0; i < tab_score.size(); i++)
        ofs << tab_score[i].first + " " + std::to_string(tab_score[i].second) + "\n";
    ofs.close();
}

void Game::end()
{
    std::pair<std::string, int> score = getPlayerScore();
    std::vector<std::pair<std::string, int>> file_score = getScore("assets/Score/score.txt");
    std::string str;
    int j = 0;

    file_score = concat_score(file_score, score);
    write_score("assets/Score/score.txt", file_score);
    while(core->device->run()) {
        core->driver->beginScene(true, true, video::SColor(0,0,0,0));
        core->driver->draw2DImage(core->images, irr::core::position2d<irr::s32>(0,0));
        if (Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 814), quit_rect) == true)
            break;
        Factory::Button_bool(core, irr::core::position2d<irr::s32>(760, 280), rectangle_rect);
        if (core->font) {
            for (auto i = _players.begin(); i != _players.end(); i++, j++) {
                str = i->get()->getName() + " " + std::to_string(i->get()->getScore());
                core->font->draw(str.c_str(), irr::core::rect<irr::s32>(960 - (str.size() * 24 / 2), 300 + 50 * j, 960 + str.size(), 650), irr::video::SColor(255,0,0,0));
            }
            j = 0;
        }
        core->driver->endScene();
    }
    _objects.clear();
    _players.clear();
}

Game::~Game()
{
}