//
// Created by TimSalguz on 13.12.2021.
//
#pragma once
#define PI 3.14159265358979323846

#include <cstdint>
#include <cmath>
#include <iostream>

const int windowWidth = 800;
const int windowHeight = 600;
double otnoshenie = double(windowHeight)/windowWidth;
const int DIMENSIONS = 3;

namespace ts
{
    struct Color
    {
        uint8_t r,g,b,alpha;
    };
    class Objects {
    public:
        struct Point {
            double coords[DIMENSIONS];
        };
        struct Angles {
            double angle[DIMENSIONS-1];
        };
        class Camera {
        public:
            Point point;
            Angles angles;
            double zeroPointDistance = 0.5;
            Point ZeroPoint()
            {
                return {point.coords[1] - cos(angles.angle[0] * PI) * zeroPointDistance, point.coords[0] - sin(angles.angle[0] * PI) * zeroPointDistance, 0};
            }

            Point ScreenPoint(double horizPixel, double vertPixel)
            {
                Point screenPoint;
                screenPoint.coords[0] = 0;
                screenPoint.coords[1] = horizPixel;
                screenPoint.coords[2] = vertPixel;
                return screenPoint;
            }
        };

        class Sphere {
        public:
            Point center;
            double r;
            Color color;
            Sphere() {};
            ~Sphere() {};
            bool IntersectionLine(double horizPixel, double vertPixel, Camera camera, Sphere sphere)
            {
                Point zeroPoint = camera.ZeroPoint();

                Point screenPoint = camera.ScreenPoint(horizPixel, vertPixel);

                double a = (screenPoint.coords[0] - zeroPoint.coords[0])* (screenPoint.coords[0] - zeroPoint.coords[0]) + (screenPoint.coords[1] - zeroPoint.coords[1])* (screenPoint.coords[1] - zeroPoint.coords[1]) + (screenPoint.coords[2] - zeroPoint.coords[2])* (screenPoint.coords[2] - zeroPoint.coords[2]);
                double b = 2 * ((screenPoint.coords[0] - zeroPoint.coords[0])*(zeroPoint.coords[0] - sphere.center.coords[0]) + (screenPoint.coords[1] - zeroPoint.coords[1])*(zeroPoint.coords[1] - sphere.center.coords[1]) + (screenPoint.coords[2] - zeroPoint.coords[2])*(zeroPoint.coords[2] - sphere.center.coords[2]));
                double c = (zeroPoint.coords[0] - sphere.center.coords[0]) * (zeroPoint.coords[0] - sphere.center.coords[0]) + (zeroPoint.coords[1] - sphere.center.coords[1]) * (zeroPoint.coords[1] - sphere.center.coords[1]) + (zeroPoint.coords[2] - sphere.center.coords[2]) * (zeroPoint.coords[2] - sphere.center.coords[2]) - sphere.r * sphere.r;
                double delta = b * b - 4 * a * c;

                if (delta > 0)
                {
                    return true;
                }
                else if (delta == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

        };

        class RayPloskost
        {
            RayPloskost() {} ;
            ~RayPloskost() {} ;

        };

        class Ploskost {
        public:

        };

        class Rectangle {
        public:

        };

        class Polygon {
        public:

        };
    };
}

