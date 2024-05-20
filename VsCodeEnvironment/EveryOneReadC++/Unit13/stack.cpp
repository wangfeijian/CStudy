#include <iostream>
#include <string>

template <typename T>
class Stack
{
private:
    unsigned int size;
    unsigned int sp;
    T *data;

public:
    Stack(unsigned int s);
    ~Stack();
    void push(T value);
    T pop();
};

template <typename T>
Stack<T>::Stack(unsigned int s)
{
    size = s;
    data = new T[size];
    sp = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <typename T>
void Stack<T>::push(T value)
{
    if (sp < size)
    {
        data[sp] = value;
        sp++;
    }
    else
    {
        std::cout << "Stack overflow!" << std::endl;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (sp > 0)
    {
        sp--;
        return data[sp];
    }
    else
    {
        std::cout << "Stack underflow!" << std::endl;
        return T();
    }
}

int main()
{
    Stack<int> s(50);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    std::cout <<"s.pop() = "<< s.pop() << std::endl;
    std::cout <<"s.pop() = "<< s.pop() << std::endl;
    std::cout <<"s.pop() = "<< s.pop() << std::endl;
    std::cout <<"s.pop() = "<< s.pop() << std::endl;

    std::cout<<"press any key to exit...";
    std::cin.get();
    return 0;
}