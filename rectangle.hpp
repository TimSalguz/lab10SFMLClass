#pragma once
#include <SFML/Graphics.hpp>

namespace ts
{
    struct Point
    {
        double x;
        double y;
    };

    class Rectangle
    {
    public:
        //Создаю конструктор, передаю в него параметры, обе точки
        Rectangle::Rectangle(Point A, double RectWidth, double RectHeight, double velocity);

        //Создаю деструктор
        ~Rectangle() { delete m_shape; }

        //Создаю функцию в классе:

        sf::RectangleShape* Get();
        void SetY(int y);
        int GetY();
        void Move();

    private:
        //Ultrasecret calculations!

        Point m_P1;
        double m_Width;
        double m_Height;
        double m_Velocity;
        int Width();
        int Height();
        void SetVelocity(int velocity);
        sf::RectangleShape* m_shape;
    };

}