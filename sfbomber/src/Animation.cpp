/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Animation
*/

#include "Animation.hpp"

Animation::Animation(std::vector<mystruct::intRect> rects, unsigned int time_frame, bool do_anim, bool destroy, unsigned int nb_cycles)
{
    _rects = rects;
    _time_frame = time_frame;
    _do_anim = do_anim;
    _destroy = destroy;
    _nb_cycles = nb_cycles;
    _actual_frame = 0;
    _start = std::chrono::steady_clock::now();
    _end = std::chrono::steady_clock::now();
}

Animation::~Animation()
{
}

void Animation::setDoAnim(bool do_anim)
{
    _do_anim = do_anim;
}

bool Animation::getDestroy() const
{
    return (_destroy);
}

unsigned int Animation::getNbCycles() const
{
    return (_nb_cycles);
}

mystruct::intRect Animation::getActualRect() const
{
    return (_rects[_actual_frame]);
}

void Animation::update()
{
    if (!_do_anim) {
        _actual_frame = 0;
        return;
    }
    _end = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > _time_frame) {
        _start = std::chrono::steady_clock::now();
        _actual_frame += 1;
        if (_actual_frame >= _rects.size()) {
            _actual_frame = 0;
            if (_nb_cycles > 0)
                _nb_cycles -= 1;
        }
    }
}