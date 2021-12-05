#include "rectangle.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define MAXELEMENTSONSCREEN 10000
#define POSKOLKOSOZDAVAT 1
#define MAXRECTWIDTH 5
#define MAXRECTHEIGHT 100
#define VYSOTAPOYAVLENIYA -1000
#define VYSOTAISCHEZANIYA 0

const int windowWidth = 1366;
const int windowHeight = 768;

using namespace std::chrono_literals;
int main()
{

    srand(static_cast<unsigned int>(time(0)));
    double random = (double (rand()%windowWidth));
    std::cout << random;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Win");

    std::vector<ts::Rectangle*> rectangles;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(rectangles.size() < MAXELEMENTSONSCREEN)

            for (int i = 0; i < POSKOLKOSOZDAVAT; ++i) {
                rectangles.push_back(new ts::Rectangle ({ (double (rand()%windowWidth)), VYSOTAPOYAVLENIYA }, 1+(rand()%MAXRECTWIDTH), 1+(rand()%MAXRECTHEIGHT), windowHeight/(double (rand()%1000))));
            }

        for(int i = 0; i < rectangles.size(); i++)
            if ((rectangles[i]->GetY()) <= windowHeight - VYSOTAISCHEZANIYA)
                rectangles[i]->Move();
            else
                rectangles.erase(rectangles.begin() + i);





            window.clear();
        for(int i = 0; i < rectangles.size(); i++)
        window.draw(*rectangles[i] ->Get());
        window.display();

        std::cout << rectangles.size() << std::endl;

        std::this_thread::sleep_for(1ms);
    }
    return 0;
}