/*通过函数来实现没有“+”号实现复数相加（没有用运算符重载）*/
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i):real(r),imag(i){}
    Complex complex_add(Complex &c);
    void display();
private:
    double real;
    double imag;
};

Complex Complex:: complex_add(Complex &c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

void Complex::display()
{
    cout<<"("<<real<<","<<imag<<"i"<<")"<<endl;
}

int main()
{
    Complex t1(1,2),t2(4,6),t3;
    t3 = t1.complex_add(t2);
    t1.display();
    t2.display();
    t3.display();
    return 0;
}
