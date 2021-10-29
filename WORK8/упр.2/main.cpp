#include<iostream>
#include<exception>
#include<stdexcept>
#include <math.h>


double speed(double path, double time)
{
    if (time == 0)
    {
        throw std::domain_error("Cannot be divided by 0");
    }
    return path / time;
}

double square(double a, double b, double c)
{
    if (a + b < c || a + c < b || c + b < a)
    {
        throw std::logic_error("This isn't a triangle");
    }
    if (a * b * c <= 0)
    {
        throw std::invalid_argument("Sides must be greater than 0");
    }
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}




int main()
{
    try
    {
        auto sp = speed(22, 0);
    }
    catch (const std::domain_error& e)
    {
        std::cerr << e.what() << '\n';
        std::abort();
    }


    try
    {
        auto sq = square(1.0, 2.0, 3.0);
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
        std::abort();
    }

    try
    {
        auto sq = square(0, 0, 0);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        std::abort();
    }

    return 0;
}
