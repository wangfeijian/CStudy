#include <iostream>
#include "./rational.h"

int main() {
    MyMath::Rational f1(3,5);
    MyMath::Rational f2(3,5);

    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;

    std::cout<<"press any key to exit";
    std::cin.get();
    return 0;
}