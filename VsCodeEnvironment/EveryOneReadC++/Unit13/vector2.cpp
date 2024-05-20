#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> v = {"apple", "banana", "orange", "grape"};
    std::sort(v.begin(), v.end());

    for (auto &s : v)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << "press any key to exit...";

    std::cin.get();
    return 0;
}