#include <iostream>
#include <string>


using namespace std;

int main() {
    string sign;
    unsigned short month = 1;
    unsigned short day = 21;

    switch (month) {
        case 1:
            sign = (day < 20) ? "Capricorn" : "Aquarius";
            break;
        case 2:
            sign = (day < 19) ? "Aquarius" : "Pisces";
            break;
        case 3:
            sign = (day < 21) ? "Pisces" : "Aries";
            break;
        case 4:
            sign = (day < 20) ? "Aries" : "Taurus";  
            break;  
        case 5:
            sign = (day < 21) ? "Taurus" : "Gemini";
            break;
        case 6:
            sign = (day < 21) ? "Gemini" : "Cancer";
            break;
        case 7:
            sign = (day < 23) ? "Cancer" : "Leo";
            break;
        case 8:
            sign = (day < 23) ? "Leo" : "Virgo";
            break;
        case 9:
            sign = (day < 23) ? "Virgo" : "Libra";
            break;
        case 10:
            sign = (day < 23) ? "Libra" : "Scorpio";
            break;
        case 11:
            sign = (day < 22) ? "Scorpio" : "Sagittarius";
            break;
        case 12:
            sign = (day < 22) ? "Sagittarius" : "Capricorn";
            break;
    }

    cout << "If your birthday is on " << month
         << "/" << day << ", your horoscope sign is " << sign << endl;
    
    cout << "press any key to exit...";
    cin.get();

    return 0;
}