#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 10;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    std::string s1 = "Hello", s2 = "World";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    std::cout<<"press any key to exit...";
    std::cin.get();
    return 0;
}