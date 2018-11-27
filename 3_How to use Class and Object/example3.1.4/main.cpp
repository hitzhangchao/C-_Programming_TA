#include <iostream>
using namespace std;

class Box
{
public:
    Box(int h,int w,int len):height(h),width(w),length(len){}//用参数初始化表对数据成员初始化
    int volume();
private:
    int height;
    int width;
    int length;
};

int Box::volume()
{
    return (height*width*length);
}

int main()
{
    Box box1(12,25,30);
    cout<<box1.volume()<<endl;
    return 0;
}
