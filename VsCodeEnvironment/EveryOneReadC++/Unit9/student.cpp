#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string name);
    virtual void Introduce() = 0;

protected:
    std::string name;
};

Person::Person(std::string name) : name(name)
{
}

class Teacher : virtual public Person
{
public:
    Teacher(std::string name, std::string subject);
    virtual void Introduce();
    void Teach();

protected:
    std::string subject;
};

Teacher::Teacher(std::string name, std::string subject) : Person(name), subject(subject)
{
}

void Teacher::Introduce()
{
    std::cout << "My name is " << name << " and I teach " << subject << std::endl;
}

void Teacher::Teach()
{
    std::cout << "I am " << name << " teaching " << subject << std::endl;
}

class Student : virtual public Person
{
public:
    Student(std::string name, int grade);
    virtual void Introduce();
    void AttendClass();

protected:
    int grade;
};

Student::Student(std::string name, int grade) : Person(name), grade(grade)
{
}

void Student::Introduce()
{
    std::cout << "My name is " << name << " and I am in grade " << grade << std::endl;
}

void Student::AttendClass()
{
    std::cout << "I am " << name << " attending class" << std::endl;
}

class TeachingStudent : public Student, public Teacher
{
public:
    TeachingStudent(std::string name, int grade, std::string subject);
    void Introduce();
};

TeachingStudent::TeachingStudent(std::string name, int grade, std::string subject) : Person(name), Student(name, grade), Teacher(name, subject)
{
}

void TeachingStudent::Introduce()
{
    std::cout << "My name is " << name << " and I am in grade " << grade << " and I teach " << subject << std::endl;
}

int main()
{
    Teacher teacher("John", "Math");
    Student student("Mary", 12);
    TeachingStudent teachingStudent("Tom", 11, "English");

    teacher.Introduce();
    student.Introduce();
    teachingStudent.Introduce();

    teacher.Teach();
    student.AttendClass();

    teachingStudent.Teach();
    teachingStudent.AttendClass();

    std::cout << "press any key to exit...";
    std::cin.get();
    return 0;
}