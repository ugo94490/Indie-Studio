/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Structs
*/

#pragma once

namespace mystruct {
    class vector3f {
        public:
            vector3f(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
            ~vector3f() = default;
            vector3f operator+(vector3f &vec) {
                vector3f res;
                res.x = x + vec.x;
                res.y = y + vec.y;
                res.z = z + vec.z;
                return (res);
            };
            vector3f operator-(vector3f &vec) {
                vector3f res;
                res.x = x - vec.x;
                res.y = y - vec.y;
                res.z = z - vec.z;
                return (res);
            };
            friend bool operator==(vector3f const &vec1, vector3f const &vec2) {
                if (vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z)
                    return (true);
                return (false);
            }
            float x;
            float y;
            float z;
    };
    class intRect {
        public:
            intRect(int _left = 0, int _top = 0, int _width = 0, int _height = 0) : left(_left), top(_top), width(_width), height(_height) {}
            ~intRect() = default;

            int left;
            int top;
            int width;
            int height;
    };
}