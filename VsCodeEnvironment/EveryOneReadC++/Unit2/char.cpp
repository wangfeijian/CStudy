#include <iostream>
using namespace std;

int main() {
    char letter = 'D';
    char tab = '\t';
    char quote = '\"';

    cout << "It's a question of character:\n";
    cout << letter << " is equivalent to " << int(letter) << endl;
    cout << tab << " is equivalent to " << int(tab) << endl;
    cout << quote << " is equivalent to " << int(quote) << endl;

    cout << "Press any key to exit...";
    cin.get();
    return 0;
}