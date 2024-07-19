#include <iostream>

using namespace std;

int ucln(int a, int b)
{
    if(b == 0) return a;
    return ucln(b, a % b);
}

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo()
    {
        this->tu = 0;
        this->mau = 1;
    }
    PhanSo(int tu, int mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    void standardize()
    {
        int uc = ucln(this->tu, this->mau);
        this->tu /= uc;
        this->mau /= uc;
    }
    friend istream &operator >>(istream &in, PhanSo &ps)
    {
        in >> ps.tu;
        in >> ps.mau;
        return in;
    }
    friend ostream &operator << (ostream &out, PhanSo ps)
    {
        ps.standardize();
        out << ps.tu << "/" << ps.mau << " ";
        return out;
    }
    friend PhanSo operator+(PhanSo p1, PhanSo p2)
    {
        PhanSo res;
        res.mau = p1.mau * p2.mau;
        res.tu = p1.mau * p2.tu + p1.tu * p2.mau;
        res.standardize();
        return res;
    }

};

int main()
{
    PhanSo p1(2,5), p2(4,6);
    PhanSo tong = p1 + p2;
    cout << p1 << p2 << tong;
    return 0;
}