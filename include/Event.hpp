/*
** EPITECH PROJECT, 2020
** Event.hpp
** File description:
** Event.hpp
*/

#pragma once

#include <irrlicht.h>

class Event : public irr::IEventReceiver
{
    public:
        virtual bool OnEvent(const irr::SEvent& event)
        {
            eve = event;
        }
        irr::SEvent eve;
};