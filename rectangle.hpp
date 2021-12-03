#pragma once

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
        Rectangle::Rectangle(Point A, double B, double C);

        //Создаю деструктор
        ~Rectangle() {/*std::cout << "Destructor's end" << std::endl;*/}

        //Создаю функцию в классе:

    private:
        //Ultrasecret calculations!

        Point m_P1;
        double m_Width;
        double m_Height;
    };
}
};


#endif //SFML_SAMPLE_RECTANGLE_HPP
