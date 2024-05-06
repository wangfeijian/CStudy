#include <iostream>
using namespace std;

int main() {
    unsigned int miles = 355;
    const float MULTIPLIER = 1.609344;
    float kilometers;

    kilometers = miles * MULTIPLIER;

    cout << miles << " miles is approximately "
    << int(kilometers + 0.5) << " kilometers." << endl;

    cout << "press enter to exit.";

    cin.get();

    // 另外几种转换操作符
    // static_cast const_cast reinterpret_cast dynamic_cast
    return 0;
}