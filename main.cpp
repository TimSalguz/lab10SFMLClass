#include "functions.hpp"
#include "objects.hpp"
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
int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    double otnoshenieStoron = double(windowHeight) / double(windowWidth);

    ts::Objects::Point A;



    sf::RenderWindow wnd(sf::VideoMode(windowWidth, windowHeight), "SFML");
    wnd.setFramerateLimit(60);

    //Цикл проверки пересечения с плоскостью (Вертикальные плоскости)
    for(int i = 0; i < windowWidth; i++)
    {
        if (IntersectionPloskost() == true)
        {

        }
    }

    sf::Texture tx;
    tx.create(windowWidth, windowHeight);
    sf::Sprite sprite(tx);
    sprite.setPosition(0, 0);
    wnd.clear();
    wnd.draw(sprite);
    wnd.display();
}





//
//
//
//struct Circle
//{
//    double coords[SKOLKOKOORDINAT];    //это x_0 и y_0
//    double angles[SKOLKOKOORDINAT-1];
//    double radius;
//};
//
//struct PointCamera
//{
//    double coords[SKOLKOKOORDINAT];
//    double angles[SKOLKOKOORDINAT-1];
//    double zeroPointDistance;
//};
//
//struct Vector
//{
//    double coords[SKOLKOKOORDINAT];
//};
//
//struct Point
//{
//    double coords[SKOLKOKOORDINAT];
//};
//struct Point2D
//{
//    double coords[2];
//};
//
//struct Color
//{
//    uint8_t r,g,b,alpha;
//};
//double dot(Point a, Point b) {return a.coords[0]*b.coords[0] + a.coords[1]*b.coords[1] + a.coords[2] * b.coords[2];}
//СДЕЛАТЬ, ЧТОБ СО СПИНЫ НЕ БЫЛО ПЕРЕСЕЧЕНИЙ
//Point2D Sphere(Point ro, Point rd, double r)
//{
//    double b = dot(ro,rd);
//    double c = dot(ro, ro) - r * r;
//    double h = b * b - c;
//   if(h < 0.0) return {-1, 0};
//    h = sqrt(h);
//    return {-b -h, -b + h};
//}
//
//
//Color PeresekaetLi(Circle A, Point B, Point C)
//{
//    double a = (C.coords[0] - B.coords[0])* (C.coords[0] - B.coords[0]) + (C.coords[1] - B.coords[1])* (C.coords[1] - B.coords[1]) + (C.coords[2] - B.coords[2])* (C.coords[2] - B.coords[2]);
//    double b = 2 * ((C.coords[0] - B.coords[0])*(B.coords[0] - A.coords[0]) + (C.coords[1] - B.coords[1])*(B.coords[1] - A.coords[1]) + (C.coords[2] - B.coords[2])*(B.coords[2] - A.coords[2]));
//    double c = (B.coords[0] - A.coords[0]) * (B.coords[0] - A.coords[0]) + (B.coords[1] - A.coords[1]) * (B.coords[1] - A.coords[1]) + (B.coords[2] - A.coords[2]) * (B.coords[2] - A.coords[2]) - A.radius * A.radius;
//    double delta = b * b - 4 * a * c;
//
//    if (delta > 0)
//    {
//        return { 255, 255, 255, 255 };
//    }
//    else if (delta == 0)
//    {
//        return{ 255, 255, 255, 50 };
//    }
//    else
//    {
//        return { 0, 0, 0, 255 };
//    }
//}
//
//int main() {
//
//
//    const int windowWidth = 800;
//    const int windowHeight = 600;
//    double otnoshenieStoron = double(windowHeight) / double(windowWidth);
//    Circle circleA;
//    //Настройка положения шара в пространстве + угол + радиус
//    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
//        circleA.coords[i] = 5;
//
//    }
//    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
//        circleA.angles[i] = 0;
//    }
//    circleA.radius = 1;
//    circleA.coords[0] = 10;
//    circleA.coords[1] = 0;
//    circleA.coords[2] = 0;
//
//    sf::RenderWindow wnd(sf::VideoMode(windowWidth, windowHeight), "SFML");
//    wnd.setFramerateLimit(60);
//
//    sf::Texture tx;
//    tx.create(windowWidth, windowHeight);
//    sf::Sprite sprite(tx);
//    sprite.setPosition(0, 0);
//
//    PointCamera camera;
//Настройка положения камеры в пространстве + угол направления взгляда + угол зрения
//    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
//        camera.coords[i] = 0;
//    }
//    camera.coords[0] = 0;
//    camera.coords[1] = 0;
//    camera.coords[2] = 0;
//    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
//        camera.angles[i] = 0;
//    }
//    camera.angles[0] = 0;
//    camera.angles[1] = 0;
//    camera.zeroPointDistance = 0.5;
//
//    Point ZP;
//    Point SP;
//
//СМЕНИТЬ ТИП МАССИВА НА ДИНАМИЧЕСКИЙ
//    Color *colorMatrix = new Color[windowHeight*windowWidth];
//
//    //Color colorMatrix[windowWidth][windowHeight];
//    //Начинаю цикл, пока количество плоскостей меньше windowHeight. у первой плоскости коорды по высоте 0,28125, и уменьшается(из 0,28125 по otnosiniestoron/windowHeight
//    while (wnd.isOpen()) {
//        sf::Event event;
//        while (wnd.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                wnd.close();
//                break;
//            }
//        }
//            double widthMatrix = -0.5;
//            double heightMatrix = otnoshenieStoron / 2;
//            //*ДОБАВИТЬ ЗАВИСИМОСТЬ SP от углов вверх-вниз, влево-вправо
//
//            ZP = {camera.coords[1] - cos(camera.angles[0] * 3.141) * 0.5,
//                  camera.coords[0] - sin(camera.angles[0] * 3.141) * 0.5, 0};
//            SP = {0, 0, otnoshenieStoron / 2};
//            int count = 0;
//            for (int i = 0; i < windowHeight; ++i) {
//                widthMatrix = -0.5;
//                for (int j = 0; j < windowWidth; ++j) {
//                    colorMatrix[count] = PeresekaetLi(circleA, ZP, {0, heightMatrix, widthMatrix});
//                    widthMatrix += 1 / double(windowWidth);
//                    count++;
//                    //colorMatrix[i*windowWidth + j] = {255,255,255,128};
//                }
//                heightMatrix -= otnoshenieStoron / double(windowHeight);
//            }
//
//            circleA.coords[0]--;
//
//            //for (int a = 0; a < windowHeight*windowWidth; ++a) {
//                    //printf("%d",colorMatrix[a].b);
//                    //Point2D intersection;
//                    //intersection = Sphere({10, 0, 0}, ZP, 5);
//            //std::cout << intersection.coords[0] << " " << intersection.coords[1];
//                    //}
//            tx.update((uint8_t *)(colorMatrix), windowWidth, windowHeight, 0, 0);
//
//            wnd.clear();
//            wnd.draw(sprite);
//            wnd.display();
//            //std::cout << widthMatrix << std::endl;
//            //std::cout << heightMatrix << std::endl;
//            //std::cout << count << std::endl;
//            //getchar();
//
//    }
//}