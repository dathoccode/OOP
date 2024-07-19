#include <iostream>

using namespace std;

class A
{
public:
    int age = 10;
public:
    friend class B;
};

class B
{
public:
    int cnt = 100;
public:
    int getAge(A test)
    {
        return test.age;
    }
    friend class A;
};

int main()
{
    A a;
    B b;
    return 0;
}
