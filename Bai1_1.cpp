#include <iostream>

using namespace std;

class Person
{
private:
    string name, dob, origin;
public:
    void nhap();
    void nhap(string _name, string _dob, string _origin);
    void in();
};

void Person :: nhap()
{
    getline(cin, name);
    getline(cin, dob);
    getline(cin, origin);
}

void Person :: nhap(string _name, string _dob, string _origin)
{
    this->name = _name;
    this->dob = _dob;
    this->origin = _origin;
}

void Person :: in()
{
    cout << name << " " << dob << " " << origin << " ";
}


class Engineer : Person
{
private:
    string major;
    int gradYear;
public:
    int getGrad()
    {
        return gradYear;
    };
    void in();
    void nhap();
    void nhap(string _name, string _dob, string _origin, string _major, int _gradYear);
};

void Engineer::nhap()
{
    Person::nhap();
    getline(cin, major);
    cin >> gradYear;
    cin.ignore();
}

void Engineer::nhap(string _name, string _dob, string _origin, string _major, int _gradYear)
{  
    Person::nhap(_name, _dob, _origin);
    this->major = _major;
    this->gradYear = _gradYear;
}

void Engineer :: in()
{
    Person::in();
    cout << major << " " << gradYear << endl;
}

Engineer curGrad(int n, Engineer *e)
{
    Engineer res = e[0];
    int max = e[0].getGrad();
    for(int i = 0; i < n; i++)
    {
        if(e[i].getGrad() > max)
        {
            max = e[i].getGrad();
            res = e[i];
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    Engineer *e = new Engineer[n];

    for(int i = 0; i < n; i++)
    {
        e[i].nhap();
    }

    for(int i = 0; i < n; i++)
    {
        e[i].in();
    }

    Engineer curGraduate = curGrad(n, e);
    curGraduate.in();


    return 0;
}