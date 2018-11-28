/*对运算符“+”进行重载，使之用于复数相加*/
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i):real(r),imag(i){}
    Complex operator + (Complex &c);
    void display();
private:
    double real;
    double imag;
};

Complex Complex:: operator + (Complex &c)  //声明运算符“+”的函数
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
    t3 = t1 + t2;
    t1.display();
    t2.display();
    t3.display();
    return 0;
}
