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

const int windowWidth = 1366;
const int windowHeight = 768;



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

struct ZeroPointCamera
{
    double coords[SKOLKOKOORDINAT];
};
struct NaprVector
{
    double coords[SKOLKOKOORDINAT];
};


struct ScreenPoint
{
    double coords[SKOLKOKOORDINAT];
};

bool PeresekaetLi(Circle A, PointCamera B)
{
    if(2==2) {
        return false;
    }
}

using namespace std::chrono_literals;
int main() {
    Circle circleA;
    //Настройка положения шара в пространстве + угол + радиус

    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
        circleA.coords[i] = 0;
    }
    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
        circleA.angles[i] = 0;
    }
    circleA.radius = 10;

    circleA.coords[0] = 0;
    circleA.coords[1] = 10000;




    PointCamera camera;
//Настройка положения камеры в пространстве + угол направления взгляда + угол зрения
    for (int i = 0; i < SKOLKOKOORDINAT; ++i) {
        camera.coords[i] = 0;
    }
    for (int i = 0; i < SKOLKOKOORDINAT - 1; ++i) {
        circleA.coords[i] = 0;
    }
    camera.viewAngle = 0;

    ZeroPointCamera ZP;

    ZP = {-1, 0, 0};

    ScreenPoint SP = {0, 0, 0};

    //Узнаю направляющий вектор прямой, выпущенной из камеры
    NaprVector napravVector;
    for (int i = 0; i < SKOLKOKOORDINAT; ++i)
    {
        napravVector.coords[i] = SP.coords[i] - ZP.coords[i];
    }
    //ОТЛАДКА
    for (int i = 0; i < SKOLKOKOORDINAT; ++i)
    {
        napravVector.coords[i] = SP.coords[i] - ZP.coords[i];
        std::cout << "NaprVector [" << i << "] coords = " << napravVector.coords[i] << std::endl;
    }


    //Находим расстояние от центра окружности до прямой



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




    PeresekaetLi(circleA, camera);


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