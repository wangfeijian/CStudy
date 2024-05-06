#include <iostream>
using namespace std;

class Rectangle
{
private:
    unsigned int width, height;

public:
    Rectangle(unsigned int width = 0, unsigned int height = 0);
    void SetSize(unsigned int width, unsigned int height);
    unsigned Area();
    unsigned Perimeter();
    bool IsSquare();
};

Rectangle::Rectangle(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
}

void Rectangle::SetSize(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
}

unsigned Rectangle::Area()
{
    return width * height;
}

unsigned Rectangle::Perimeter()
{
    return 2 * (width + height);
}

bool Rectangle::IsSquare()
{
    return (width == height);
}

int main()
{
    Rectangle rect;
    rect.SetSize(5, 7);

    cout << "Area: " << rect.Area() << endl;
    cout << "Perimeter: " << rect.Perimeter() << endl;
    cout << "Is Square: " << rect.IsSquare() << endl;

    cout << "press any key to exit...";
    getchar();
    return 0;
}