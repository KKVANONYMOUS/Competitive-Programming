#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a, b;

public:
    friend void sum(Complex, Complex); 
    void setNumber(int real, int complex)
    {
        a = real;
        b = complex;
    }
    void display()
    {
        cout << a << " + " << b << "i";
    }
};

//we can also make a class as friend
void sum(Complex o1, Complex o2)
{
    cout << (o1.a + o2.a) << " + " << (o1.b + o2.b) << "i";
}
int main()
{
    Complex o1, o2;
    o1.setNumber(2, 4);
    o2.setNumber(1, 5);
    sum(o1, o2);
    return 0;
}