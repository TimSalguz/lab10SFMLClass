#include "rectangle.hpp"
#include <iostream>

namespace ts
{
    Rectangle::Rectangle(Point A, double B, double C)
    {
        m_P1 = A;
        m_Width = B;
        m_Height = C;
        m_velocity = velocity;
        m_shape = new sf::CircleShape(m_r);
        Rect1 -> setOrigin(m_r, m_r);
        m_shape->setFillColor(sf::Color::White);
        m_shape->setPosition(m_x, m_y);


        if (m_Width == 0 || m_Height == 0)
        {
            m_Width = 5;
            m_Height = 10;
            std::cout << "This rectangle doesn't exist!.\n"
                         "Now width  = "
                      << m_Width << ", height = " << m_Height << std::endl;
        }
        //std::cout << "Constructor's end" << std::endl;
    }

}