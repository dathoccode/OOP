#include <iostream>

using namespace std;

class Vehicle
{
private:
    int pubYear;
    float weight;
public:
    Vehicle()
    {

    };
    int getPubYear()
    {
        return pubYear;
    }
    float getWeight()
    {
        return weight;
    }
    Vehicle(int pubYear, float weight)
    {
        this->pubYear = pubYear;
        this->weight = weight;
    }
    float cost()
    {
        return pubYear * 0.2 + weight;
    }
    virtual void print()
    {
        cout << pubYear << " " << weight << " " << cost() << endl;
    }

};

class Truck : public Vehicle
{
private:
    float loadout;
public:
    Truck()
    {
        cout << "contructor called" << endl;
    };
    Truck(int pubYear, float weight, float loadout) : Vehicle(pubYear, weight)
    {
        this->loadout = loadout;
    }
    float cost()
    {
        return loadout * 200;
    }
    void print()
    {
        cout << getPubYear() << " " << getWeight() << " " << loadout << " " << cost() << endl;
    }


};

int main()
{
    Vehicle *p = new Vehicle(2005, 1023);
    p->print();
    p = new Truck(2308, 1000, 90);
    p->print();
    return 0;
}