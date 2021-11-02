#include<iostream>
#include<exception>
#include<stdexcept>
#include <math.h>
#include <vector>


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

double fraction(int a, int b){
    if(b == 0){
        throw std::invalid_argument("division by zero");
    }

    return (a*1.0/b);
}


int main() {
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
        auto sq = square(1, 1, 2);
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

    int numerator, denominator;
    std::cout << "Enter numerator:" << std::endl;
    std::cin >> numerator;
    std::cout << "Enter denominator:" << std::endl;
    std::cin >> denominator;

    try {
        std::cout << fraction(numerator, denominator) << std::endl;
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        std::abort();
    }

    try {
        std::vector<int> a;
        a.pop_back();
    }
    catch (std::exception& e) {
        std::cout << "error out of range" << std::endl;
        std::cerr << "Standard exception:" << e.what() << '\n';
        std::abort();
    }

    return 0;
}
