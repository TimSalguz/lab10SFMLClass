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
    double viewAngle;
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
        std::cout << "@";
        return { 255, 255, 255, 0 };
    }
    else if (delta == 0)
    {
        std::cout << "#";
        return{ 255, 0, 0, 0 };
    }
    else
    {
        std::cout << " ";
        return { 1, 1, 1, 1 };
    }
}

int main() {



    const int windowWidth = 120;
    const int windowHeight = 30;
    double otnoshenieStoron = double(windowHeight)/double(windowWidth);
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






    PointCamera camera;
//Настройка положения камеры в пространстве + угол направления взгляда + угол зрения
    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
        camera.coords[i] = 0;
    }
    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
        camera.coords[i] = 0;
    }
    camera.viewAngle = 0;

    Point ZP;

    ZP = {-0.5, 0, 0};

    Point SP = {0, 0, otnoshenieStoron/2};
//СМЕНИТЬ ТИП МАССИВА НА ДИНАМИЧЕСКИЙ
    Color **colorMatrix = new Color*[windowWidth];
    for (int i = 0; i < windowWidth; i++)
    {
        colorMatrix[i] = new Color[windowHeight];
    }

    //Color colorMatrix[windowWidth][windowHeight];
    //Начинаю цикл, пока количество плоскостей меньше windowHeight. у первой плоскости коорды по высоте 0,28125, и уменьшается(из 0,28125 по otnosiniestoron/windowHeight
    //*ДОБАВИТЬ ЗАВИСИМОСТЬ SP от углов вверх-вниз, влево-вправо
    for ( ; ; ) {
        int count = 0;
        double widthMatrix = -0.5;
        double heightMatrix = otnoshenieStoron / 2;

        for (int i = 0; i < windowHeight; ++i) {
            widthMatrix = -0.5;
            for (int j = 0; j < windowWidth; ++j) {
                colorMatrix[j][i] = PeresekaetLi(circleA, ZP, {0, widthMatrix, heightMatrix});
                widthMatrix += 1 / double(windowWidth);
            }
            heightMatrix -= otnoshenieStoron / double(windowHeight);
        }
        circleA.coords[0] += 1;



        //std::cout << widthMatrix << std::endl;
        //std::cout << heightMatrix << std::endl;
        //std::cout << count << std::endl;

        //getchar();
    }
    //Нахожу еще точку, лежащую на плоскости
    //Point NaPloskostiA =
    //Нахожу уравнение плоскости через точку, лежащую на ней и нормальный вектор
    //double uravneniePloskostiX, uravneniePloskostiY, uravneniePloskostiZ;
    //uravneniePloskostiX = normalVector.coords[0]*(-)
    //Если плоскость и шар пересекаются, то


    //Находим пересечение прямой и круга



//    if (ZP.coords[0]!=SP.coords[0]) {
//        double k = (SP.coords[1] - ZP.coords[1]) / (SP.coords[0] - ZP.coords[0]);
//
//        double b = ZP.coords[1] * ((SP.coords[0] * k));
//
//        double a = 1 + k * k;
//
//        double c = circleA.coords[0] * circleA.coords[0] + b * b - 2 * circleA.coords[1] * b +
//                   circleA.coords[1] * circleA.coords[1] - circleA.radius * circleA.radius;
//
//        double D = 4 * (b * k - circleA.coords[0] - circleA.coords[1] * k) *
//                       (b * k - circleA.coords[0] - circleA.coords[1] * k) - 4 * a * c;
//
//        if (D >= 0)
//            std::cout << "Peresekaet";
//        else
//            std::cout << "Ne peresekaet";
//    }
//    else if(ZP.coords[0]==SP.coords[0] && ZP.coords[1]!=SP.coords[1])
//    {
//        if(ZP.coords[0]>=circleA.coords[0]-circleA.radius && ZP.coords[0]<=circleA.coords[0]+circleA.radius)
//            std::cout<<"Peresekaet";
//        else
//            std::cout<<"Ne peresekaet";
//    }
//    else
//        std::cout<<"Points are equal";




    //PeresekaetLi(circleA, camera);


//
//    srand(static_cast<unsigned int>(time(0)));
//    double random = (double (rand()%windowWidth));
//    std::cout << random;
//    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Win");
//
//    std::vector<ts::Rectangle*> rectangles;
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        if(rectangles.size() < MAXELEMENTSONSCREEN)
//
//            for (int i = 0; i < POSKOLKOSOZDAVAT; ++i) {
//                rectangles.push_back(new ts::Rectangle ({ (double (rand()%windowWidth)), VYSOTAPOYAVLENIYA }, 1+(rand()%MAXRECTWIDTH), 1+(rand()%MAXRECTHEIGHT), windowHeight/(double (rand()%1000))));
//            }
//
//        for(int i = 0; i < rectangles.size(); i++)
//            if ((rectangles[i]->GetY()) <= windowHeight - VYSOTAISCHEZANIYA)
//                rectangles[i]->Move();
//            else
//                rectangles.erase(rectangles.begin() + i);
//
//
//
//
//
//            window.clear();
//        for(int i = 0; i < rectangles.size(); i++)
//        window.draw(*rectangles[i] ->Get());
//        window.display();
//
//        std::cout << rectangles.size() << std::endl;
//
//        std::this_thread::sleep_for(1ms);
//    }
//    return 0;
}