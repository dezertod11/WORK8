#include <iostream>
#include <windows.h>

double calculate(int a, int b){
    if(b == 0){
        throw std::invalid_argument("Знаменатель 0");
    }

    return (a*1.0/b);
}

class Array{
private:
    int size;
    int *arr;
public:
    Array(int sz): size(sz){arr = new int[sz];}
    int& operator[](int index){
        if(index > size){
            throw std::range_error("ошибка overflow");
        }

        return arr[index];
    };
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int numerator, denominator;
    std::cout << "Введите числитель:" << std::endl;
    std::cin >> numerator;
    std::cout << "Введите знаменатель:" << std::endl;
    std::cin >> denominator;

    try{
        std::cout << calculate(numerator, denominator) << std::endl;
    } catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }

    int size, index;
    std::cout << "Введите длину массива: " << std::endl;
    std::cin >> size;
    Array arr(size);
    std::cout << "Введите индекс элемента, которые преобразуем в 1: " << std::endl;
    std::cin >> index;
    try {
        arr[index] = 1;
        std::cout << arr[index] << std::endl;
        std::cout << "Нет проблем" << std::endl;
    } catch (std::range_error& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}










