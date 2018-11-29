#include <iostream>
#include <cmath>
#include "matrix_class.h"

using namespace std;

int main()
{
    /*test--平面三个转动关节机械臂正运动学计算*/
    TransformMatrix T1(PI/4,0,0,0);
    T1.display();
    TransformMatrix T2(3*PI/4,40,0,0);
    T2.display();
    TransformMatrix T3(-PI/2,20,0,0);
    T3.display();
    TransformMatrix Tool(0,15,0,0);
    Tool.display();
    TransformMatrix Tf = T1* T2* T3* Tool;
    Tf.display();

    return 0;
}
