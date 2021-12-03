#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "rectangle.hpp"

int main()
{
    srand(time(0));

    sf::Texture background;
    if (!background.loadFromFile("backgroung.jpg"))
    {
        std::cout << "ERROR: not found background.jpg" << std::endl;
        return -1;
    }
    sf::Sprite Background(background);

    const int WindowWidth = 1366;
    const int WindowHeight = 768;

    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Lab 10 Salimguzhinov T 1PM-3 Variant 1");

    ts::Point A = {10, 10};
    ts::Rectangle(A, 10, 20);

    sf::RectangleShape Rect1(ts::Rectangle);

    sf::.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for(int i = 0; i<WindowWidth/10; i++)


        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}