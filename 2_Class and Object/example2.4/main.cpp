//找出一个整形数组中的元素的最大值
#include <iostream>
using namespace std;

class Array_max
{
public:
    void set_value();
    void max_value();
    void display_value();
private:
    int array[10];
    int max;
};

void Array_max::set_value()
{
    for (int i=0;i<10;i++)
        cin>>array[i];
}

void Array_max::max_value()
{
    max=array[0];
    for(int i=1;i<10;i++)
    {
        if(array[i]>max)
            max=array[i];
    }
}

void Array_max::display_value()
{
    cout<<"max_value = "<<max<<endl;
}

int main()
{
    Array_max array1_max;
    array1_max.set_value();
    array1_max.max_value();
    array1_max.display_value();
    return 0;
}
