#include <iostream>
#include <math.h>

class Point
{
private:
    int x, y;
public:
    Point(int x, int y);
    float getDistance(Point p);
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

float Point::getDistance(Point p)
{
    float res = 0;
    res = sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    return res;
}


using namespace std;

int main()
{
    Point p1(1, 3), p2(1,3), p3(2,4);
    cout << p1.getDistance(p2) << endl;
    cout << p1.getDistance(p3) << endl;


    return 0;
}