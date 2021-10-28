#include <iostream>
#include "fraction.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Rat::Rational number(1, 2);
    std::cout << number << " = " << double(number) << "; " << bool(number) << '\n';

    Rat::Rational number1;
    number1.set_num_and_den(2, 3);
    std::cout << "Числитель: " << number.get_num() << "; Знаменатель: " << number.get_den()<<std::endl;

    try {
        Rat::Rational number2(1, 0);
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }

    try {
        Rat::Rational number3;
        number1.set_num_and_den(1, 0);
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }

    try {
        std::cout << number1 << " - " << number << " = " << number1 - number << std::endl;
        std::cout << number1 << " + " << number << " = " << number1 + number << std::endl;
        std::cout << number1 << " * " << number << " = " << number1 * number << std::endl;
        std::cout << number1 << " / " << number << " = " << number1 / number << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }
    
    number += 2;
    std::cout << number << " - " << 2 << " = " << number - 2 << std::endl;

    number1--;
    std::cout << number1 << " - " << 1 << " = " << number1 - 1 << std::endl;

    if (number1 >= number)
    {
        std::cout << number1 << " - " << number << " >= 0 ";
    }
    else
    {
        std::cout << number1 << " - " << number << " < 0 ";
    }
}