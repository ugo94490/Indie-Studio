/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Explosion
*/

#include "Explosion.hpp"
#include "Factory.hpp"

Explosion::Explosion(float x, float y, float z, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    _pos = {x, y, z};

    //lucas
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    //lucas

    //particles
    particleSystem = smgr->addParticleSystemSceneNode(true);
	irr::scene::IParticleEmitter* emitter = particleSystem->createBoxEmitter(
        core::aabbox3d<f32>(-7,0,-7,7,1,7), // taille de l'émetteur
        core::vector3df(0.0f,0.09f,0.0f),   // position initiale
        80,100,                             // taux d'émission
        video::SColor(0,255,255,255),       // la couleur la plus sombre
        video::SColor(0,255,255,255),       // la couleur la plus lumineuse
        800,2000,0,                         // minimum et maximum âge, angle
        core::dimension2df(10.f,10.f),         // taille minimum
        core::dimension2df(20.f,20.f));        // taille maximum
	particleSystem->setEmitter(emitter);    // on attache l'emetteur
	emitter->drop();                        // plus besoin de ca
	irr::scene::IParticleAffector* paf = particleSystem->createFadeOutParticleAffector();
    particleSystem->addAffector(paf); // de même pour l'affecteur
    paf->drop();
    particleSystem->setPosition(irr::core::vector3df(x,y,z));
    particleSystem->setScale(irr::core::vector3df(2,2,2));
    particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    particleSystem->setMaterialTexture(0, driver->getTexture("assets/textures/fire.bmp"));
    particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    //particles

    _dead = false;
    _start = std::chrono::steady_clock::now();
}

Explosion::Explosion(irr::core::vector3d<f32> pos, scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
    _pos = pos;

    //lucas
    scene::IAnimatedMesh* mesh = Factory::Check_mesh(smgr, "assets/textures/box.MD3");
    _node = smgr->addAnimatedMeshSceneNode(mesh);
    _node->setPosition(_pos);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMaterialTexture(0, Factory::Check_load(driver, "assets/textures/box.jpg"));
    //lucas

    //particles
    particleSystem = smgr->addParticleSystemSceneNode(true);
	irr::scene::IParticleEmitter* emitter = particleSystem->createBoxEmitter(
        core::aabbox3d<f32>(-7,0,-7,7,1,7), // taille de l'émetteur
        core::vector3df(0.0f,0.09f,0.0f),   // position initiale
        80,100,                             // taux d'émission
        video::SColor(0,255,255,255),       // la couleur la plus sombre
        video::SColor(0,255,255,255),       // la couleur la plus lumineuse
        800,2000,0,                         // minimum et maximum âge, angle
        core::dimension2df(10.f,10.f),         // taille minimum
        core::dimension2df(20.f,20.f));        // taille maximum
	particleSystem->setEmitter(emitter);              // on attache l'emetteur
	emitter->drop();                                  // plus besoin de ca
	irr::scene::IParticleAffector* paf = particleSystem->createFadeOutParticleAffector();
    particleSystem->addAffector(paf); // de même pour l'affecteur
    paf->drop();
    particleSystem->setPosition(irr::core::vector3df(pos.X, pos.Y, pos.Z));
    particleSystem->setScale(irr::core::vector3df(2,2,2));
    particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    particleSystem->setMaterialTexture(0, driver->getTexture("assets/textures/fire.bmp"));
    particleSystem->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    //particles

    _dead = false;
    _start = std::chrono::steady_clock::now();
}

Explosion::~Explosion()
{
    _node->remove();
    particleSystem->clearParticles();
    particleSystem->remove();
}

void Explosion::update(std::list<std::shared_ptr<GameObject>> &objs, float const &timepassed)
{
    (void)objs;
    (void)timepassed;
    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 600) {
        _dead = true;
    }
}

GameObject::ObjTypes Explosion::getType() const
{
    return (ObjTypes::EXPLOSION);
}

irr::core::vector3d<f32> Explosion::getPos() const
{
    return (_pos);
}

bool Explosion::do_remove() const
{
    return (_dead);
}

scene::IAnimatedMeshSceneNode *Explosion::getNode() const
{
    return (_node);
}

void Explosion::setNode(scene::IAnimatedMeshSceneNode *node)
{
    _node = node;
}