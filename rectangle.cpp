//#include "rectangle.hpp"
//#include <iostream>

//namespace ts
//{
//    Rectangle::Rectangle(Point A, double Width, double Heigth, double velocity)
//    {
//        m_P1 = A;
//        m_Width = Width;
//        m_Height = Heigth;
//        m_Velocity = velocity;
//
//
//        if (m_Width == 0 || m_Height == 0)
//        {
//            m_Width = 5;
//            m_Height = 10;
//            std::cout << "This rectangle doesn't exist!.\n"
//                         "Now width  = "
//                      << m_Width << ", height = " << m_Height << std::endl;
//
//        }
//        Point B;
//
//        m_shape = new sf::RectangleShape(sf::Vector2f(m_Width, m_Height));
//
//        m_shape->setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
//        m_shape->setPosition(A.x, A.y);
//
//        //std::cout << "Constructor's end" << std::endl;
//    }
//
//    int Rectangle::Width()
//    {
//        return m_Width;
//    }
//
//    int Rectangle::Height()
//    {
//        return m_Height;
//    }
//
//    void Rectangle::SetVelocity(int velocity)
//    {
//        m_Velocity = velocity;
//    }
//
//    sf::RectangleShape* Rectangle::Get() { return m_shape; }
//
//    void Rectangle::SetY(int y)
//    {
//        m_P1.y = y;
//        m_shape->setPosition(m_P1.x, m_P1.y);
//    }
//
//    int Rectangle::GetY() { return m_P1.y; }
//
//    void Rectangle::Move()
//    {
//        m_P1.y += m_Velocity;
//        m_shape->setPosition(m_P1.x, m_P1.y);
//    }

//}