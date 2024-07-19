#include <iostream>
#include <math.h>

using namespace std;

class Time
{
private:
    int hours, minutes, seconds;
public:
    Time();
    Time(int hour, int minutes, int seconds);
    ~Time();
    void display();
    int getHours();
    int getMinutes();
    int getSeconds();
    void add(Time t);
    void standadize();
};

Time::Time()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}


Time::~Time()
{
    cout << "Time destroyed" << endl;
}

void Time::display()
{
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

int Time::getHours()
{
    return this->hours;
}
int Time::getMinutes()
{
    return this->minutes;
}
int Time::getSeconds()
{
    return this->seconds;
}

void Time::standadize()
{
    this->minutes += this->seconds / 60;
    this->seconds %= 60;
    this->hours += this->minutes / 60;
    this->minutes %= 60;
    this->hours %= 24;
}

void Time::add(Time t)
{
    this->hours += t.hours;
    this->minutes += t.minutes;
    this->seconds += t.seconds;
}

int main()
{
    Time a, b(1, 1, 1), c(232, 321, 3421), d(23, 59, 59), e(0 ,0, 1);
    d.standadize();
    d.display();
    d.add(e);
    cout << "hongngoc" << endl;
    d.standadize();
    d.display();
    return 0;
}