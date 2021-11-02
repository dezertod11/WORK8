#include <iostream>
#include "fraction.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Rat::Rational number(1, 2);
    std::cout << number << " = " << double(number) << "; " << bool(number) << '\n';

    Rat::Rational number1;
    number1.set(2, 3);
    std::cout << "Числитель: " << number.get_num() << "; Знаменатель: " << number.get_den()<<std::endl;

    try {
        Rat::Rational number0(1, 0);
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }

    try {
        number1.set(1, 0);
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }

    try {
        std::cout << number1 << " / " << number << " = " << number1 / number << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cout << "\n" << e.what();
    }

}