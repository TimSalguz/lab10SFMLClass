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
const float mouseSensitivity = 0.001;


using namespace std::chrono_literals;
int main()
{
    const float PI = acos(-1);

    ts::Camera cam(windowWidth,windowHeight,{0,0,10},{0,0,0}, {windowWidth,static_cast<float>(double(otnoshenie) * double(windowHeight)),windowWidth/2,windowHeight/2});

    sf::RenderWindow wnd(sf::VideoMode(cam.Width(), cam.Height()), "SFML");
    wnd.setFramerateLimit(60);
    wnd.setMouseCursorVisible(false);
    sf::Texture tx;
    tx.create(cam.Width(), cam.Height());
    sf::Sprite sprite(tx);
    float mouseX = 0;
    float mouseY = 0;
    while (wnd.isOpen()) {
        sf::Event event;
        mouseX = 0;
        mouseY = 0;
        while (wnd.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                wnd.close();
                break;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                int mx = event.mouseMove.x - windowWidth / 2;
                int my = event.mouseMove.y - windowHeight / 2;
                mouseX += float(mx)*mouseSensitivity;
                mouseY += float(my)*mouseSensitivity;
                cam.dRoll(-mouseY);
                cam.dPitch(-mouseX);
                sf::Mouse::setPosition(sf::Vector2i(windowWidth/2, windowHeight / 2), wnd);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            cam.dYaw(-0.01);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            cam.dYaw(+0.01);
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
        //double distance = sqrt(cam.GetX() * cam.GetX() + cam.GetY()*cam.GetY() + cam.GetZ()*cam.GetZ());
        //if (distance < 0.5)
        //    distance = 0.5;

        for(float i=-5;i<=5;i+=0.04)
            for(float j=-5;j<=5;j+=0.04) {
                cam.ProjectPoint({(float) i, (float) j, 3}, {0,255,150,253});
                //cam.ProjectPoint({1, (float) i, (float) j});
            }

        int r = 1;
        for(float i=0;i<PI/2;i+=0.05)
            for(float j=0;j<2*PI;j+=0.05)
                cam.ProjectPoint({r*sin(i)*cos(j), r*sin(i)*sin(j), r*cos(i)*cos(j)}, {255,0,0,255});


            ts::Point center = {1,1,1};

        for(float i=0;i<PI;i+=0.04)
            for(float j=0;j<2*PI;j+=0.04)
                cam.ProjectPoint({center.x- r*sin(i)*cos(j), center.y-r*sin(i)*sin(j), center.z-r*cos(i)}, {255,255,0,255});

        for(float i=0;i<5;i+=0.1)
            for(float j=0;j<5;j+=0.1)
                cam.ProjectPoint({10-(i), (j), (i)}, {255,122,0,255});

        for(float i = 0; i<1; i+=0.1)
            for (float j = 0; j < 1; j+=0.1)
                for (float k = 0; k < 1; k+=0.1)
                    cam.ProjectPoint({-4-i,-4-j,-4-k},{255,255,255,255});


        tx.update((uint8_t *) cam.Picture(), cam.Width(), cam.Height(), 0, 0);
        sprite.setPosition(0, 0);
        wnd.clear();
        wnd.draw(sprite);
        wnd.display();
    }
}