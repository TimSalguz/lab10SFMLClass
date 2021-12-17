#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "rectangle.hpp"
const int windowWidth = 1920;
const int windowHeight = 1080;
const double otnoshenie = double(windowWidth)/windowHeight;


using namespace std::chrono_literals;
int main()
{
    const float PI = acos(-1);

    ts::Camera cam(windowWidth,windowHeight,{0,0,0},{0,0,0}, {windowWidth,static_cast<float>(double(otnoshenie) * double(windowHeight)),windowWidth/2,windowHeight/2});

    sf::RenderWindow wnd(sf::VideoMode(cam.Width(), cam.Height()), "SFML");
    wnd.setFramerateLimit(60);
    wnd.setMouseCursorVisible(true);
    sf::Texture tx;
    tx.create(cam.Width(), cam.Height());
    sf::Sprite sprite(tx);

    while (wnd.isOpen()) {
        sf::Event event;
        while (wnd.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                wnd.close();
                break;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            cam.dZ(-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            cam.dX(0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            cam.dZ(0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            cam.dX(-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            cam.dY(+0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            cam.dY(-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cam.dPitch(0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cam.dPitch(-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cam.dRoll(-0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cam.dRoll(0.1);
        }

        cam.Clear();
        //std::cout << cam.Width() << cam.Height() << std::endl;
        std::cout << cam.GetX() << cam.GetY() << cam.GetZ() << std::endl;
        double distance = sqrt(cam.GetX()*cam.GetX() + cam.GetY()*cam.GetY() + cam.GetZ()*cam.GetZ());
        if (distance <= 0.5)
            distance = 0.5;

        for(float i=-5;i<=5;i+=distance/100+0.01)
            for(float j=-5;j<=5;j+=distance/100+0.01) {
                cam.ProjectPoint({(float) i, (float) j, 3}, {0,255,255,100});
                //cam.ProjectPoint({1, (float) i, (float) j});
            }

        int r = 1;
        for(float i=0;i<PI/2;i+=distance/200+0.001)
            for(float j=0;j<2*PI;j+=distance/200+0.001)
                cam.ProjectPoint({r*sin(i)*cos(j), r*sin(i)*sin(j), r*cos(i)*cos(j)}, {255,0,0,128});


        for(float i=0;i<PI/2;i+=distance/100+0.001)
            for(float j=0;j<2*PI;j+=distance/200+0.001)
                cam.ProjectPoint({10-r*sin(i)*cos(j), 10-r*sin(i)*sin(j), 10-r*cos(i)*sin(j)}, {255,255,0,128});

        tx.update((uint8_t *) cam.Picture(), cam.Width(), cam.Height(), 0, 0);
        sprite.setPosition(0, 0);
        wnd.clear();
        wnd.draw(sprite);
        wnd.display();
    }
}