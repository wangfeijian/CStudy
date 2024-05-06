#include <iostream>
using namespace std;

unsigned long long Factorial(unsigned int n);
void PropmtWait();

int main() {
    unsigned int n;
    cout << "Enter a number to find its factorial: ";
    while(!(cin >> n)){
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    unsigned long long result = Factorial(n);
    cout << "The factorial of " << n << " is " << result << endl;

    PropmtWait();
    return 0;
}

void PropmtWait() {
    cin.ignore(10000, '\n');
    cout << "Press any key to continue...";
    getchar();
}

unsigned long long Factorial(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return n * Factorial(n - 1);
    }
}