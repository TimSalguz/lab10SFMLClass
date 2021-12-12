#include "rectangle.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define SKOLKOKOORDINAT 3
#define DALNOSTZRENIYA 1000
using namespace std::chrono_literals;



struct Circle
{
    double coords[SKOLKOKOORDINAT];    //это x_0 и y_0
    double angles[SKOLKOKOORDINAT-1];
    double radius;
};

struct PointCamera
{
    double coords[SKOLKOKOORDINAT];
    double angles[SKOLKOKOORDINAT-1];
    double zeroPointDistance;
};

struct Vector
{
    double coords[SKOLKOKOORDINAT];
};

struct Point
{
    double coords[SKOLKOKOORDINAT];
};

struct Color
{
    short r,g,b,alpha;
};


Color PeresekaetLi(Circle A, Point B, Point C)
{
    double a = (C.coords[0] - B.coords[0])* (C.coords[0] - B.coords[0]) + (C.coords[1] - B.coords[1])* (C.coords[1] - B.coords[1]) + (C.coords[2] - B.coords[2])* (C.coords[2] - B.coords[2]);
    double b = 2 * ((C.coords[0] - B.coords[0])*(B.coords[0] - A.coords[0]) + (C.coords[1] - B.coords[1])*(B.coords[1] - A.coords[1]) + (C.coords[2] - B.coords[2])*(B.coords[2] - A.coords[2]));
    double c = (B.coords[0] - A.coords[0]) * (B.coords[0] - A.coords[0]) + (B.coords[1] - A.coords[1]) * (B.coords[1] - A.coords[1]) + (B.coords[2] - A.coords[2]) * (B.coords[2] - A.coords[2]) - A.radius * A.radius;
    double delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        return { 255, 255, 0, 125 };
    }
    else if (delta == 0)
    {
        return{ 255, 255, 0, 125 };
    }
    else
    {
        return { 0, 0, 1, 125 };
    }
}

int main() {


    const int windowWidth = 120;
    const int windowHeight = 30;
    double otnoshenieStoron = double(windowHeight) / double(windowWidth);
    Circle circleA;
    //Настройка положения шара в пространстве + угол + радиус

    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
        circleA.coords[i] = 5;

    }
    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
        circleA.angles[i] = 0;
    }
    circleA.radius = 1;
    circleA.coords[0] = 10;
    circleA.coords[1] = 0;
    circleA.coords[2] = 0;

    sf::RenderWindow wnd(sf::VideoMode(800, 600), "SFML");
    sf::Texture tx;
    tx.create(120, 30);
    sf::Sprite sprite(tx);
    sprite.setPosition(50, 50);


    PointCamera camera;
//Настройка положения камеры в пространстве + угол направления взгляда + угол зрения
    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
        camera.coords[i] = 0;
    }
    camera.coords[0] = 0;
    camera.coords[1] = 0;
    camera.coords[2] = 0;
    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
        camera.angles[i] = 0;
    }
    camera.angles[0] = 0;
    camera.angles[1] = 0;
    camera.zeroPointDistance = 0.5;

    Point ZP;
    Point SP;

//СМЕНИТЬ ТИП МАССИВА НА ДИНАМИЧЕСКИЙ
    Color *colorMatrix = new Color[windowHeight*windowWidth];

    //Color colorMatrix[windowWidth][windowHeight];
    //Начинаю цикл, пока количество плоскостей меньше windowHeight. у первой плоскости коорды по высоте 0,28125, и уменьшается(из 0,28125 по otnosiniestoron/windowHeight
    while (wnd.isOpen()) {
        sf::Event event;
        while (wnd.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                wnd.close();
                break;
            }
            double widthMatrix = -0.5;
            double heightMatrix = otnoshenieStoron / 2;
            //*ДОБАВИТЬ ЗАВИСИМОСТЬ SP от углов вверх-вниз, влево-вправо

            ZP = {camera.coords[1] - cos(camera.angles[0] * 3.141) * 0.5,
                  camera.coords[0] - sin(camera.angles[0] * 3.141) * 0.5, 0};
            SP = {0, 0, otnoshenieStoron / 2};
            int count = 0;
            for (int i = 0; i < windowHeight; ++i) {
                widthMatrix = -0.5;
                for (int j = 0; j < windowWidth; ++j) {
                    colorMatrix[count] = PeresekaetLi(circleA, ZP, {0, heightMatrix, widthMatrix});
                    widthMatrix += 1 / double(windowWidth);
                    count++;
                    //colorMatrix[i*windowWidth + j] = {255,255,255,128};
                }
                heightMatrix -= otnoshenieStoron / double(windowHeight);
            }
            camera.angles[0] += 0.0;


            for (int a = 0; a < windowHeight*windowWidth; ++a) {
                    printf("%d",colorMatrix[a].b);

            }
            tx.update((sf::Uint8 *)colorMatrix, windowWidth, windowHeight, 0, 0);

            wnd.clear();
            wnd.draw(sprite);
            wnd.display();
            //std::cout << widthMatrix << std::endl;
            //std::cout << heightMatrix << std::endl;
            //std::cout << count << std::endl;
            //getchar();
        }
    }
}