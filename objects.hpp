//
// Created by TimSalguz on 13.12.2021.
//
#pragma once
#define DIMENSIONS 3

namespace ts
{
    class Objects {
    public:
        class Point {
        public:
            Point(){};
            ~Point(){};
            double coords[DIMENSIONS];
        };


        class Sphere {
            Point center;
            double r;
        };

        class Ploskost {

        };

        class Rectangle {

        };

        class Polygon {

        };
    };
}

