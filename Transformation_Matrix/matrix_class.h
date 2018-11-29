#ifndef MATRIX_CLASS_H_INCLUDED
#define MATRIX_CLASS_H_INCLUDED

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.1415927;

class TransformMatrix
{
public:
    TransformMatrix();
    TransformMatrix(
        float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44);
    TransformMatrix(float rads,float x,float y,float z);

    TransformMatrix operator + (const TransformMatrix &rhs);
    TransformMatrix operator - (const TransformMatrix &rhs);
    TransformMatrix operator * (const TransformMatrix &rhs);
    TransformMatrix Invert();                      //声明求逆函数

    void display();
private:
    float mData[4][4];
};

/*构造函数--建立4x4单位阵*/
TransformMatrix::TransformMatrix()                        //构造函数 赋初值成4x4单位阵
{
    for( int i = 0; i < 4; ++i )
    {
        for( int j = 0; j < 4; ++j )
        {
            if( i == j )
                mData[i][j] = 1.0f;
            else
                mData[i][j] = 0.0f;
        }
    }
}

/*构造函数--手动建立4x4变换矩阵*/
TransformMatrix::TransformMatrix(
    float m11, float m12, float m13, float m14,
    float m21, float m22, float m23, float m24,
    float m31, float m32, float m33, float m34,
    float m41, float m42, float m43, float m44 )
{
    mData[0][0] = m11;mData[0][1] = m12;mData[0][2] = m13;mData[0][3] = m14;
    mData[1][0] = m21;mData[1][1] = m22;mData[1][2] = m23;mData[1][3] = m24;
    mData[2][0] = m31;mData[2][1] = m32;mData[2][2] = m33;mData[2][3] = m34;
    mData[3][0] = m41;mData[3][1] = m42;mData[3][2] = m43;mData[3][3] = m44;
}

/*构造函数--通过平移和旋转建立变换矩阵*/
TransformMatrix::TransformMatrix(float rads,float x,float y,float z)
{
    mData[0][0] = cos(rads);mData[0][1] = -sin(rads);mData[0][2] = 0; mData[0][3] = x;
    mData[1][0] = sin(rads);mData[1][1] = cos(rads); mData[1][2] = 0; mData[1][3] = y;
    mData[2][0] = 0;        mData[2][1] = 0;         mData[2][2] = 1; mData[2][3] = z;
    mData[3][0] = 0;        mData[3][1] = 0;         mData[3][2] = 0; mData[3][3] = 1;
}

/*矩阵加法“+”运算符重载*/
TransformMatrix TransformMatrix::operator + ( const TransformMatrix &rhs )
{
    TransformMatrix result;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            result.mData[i][j] = mData[i][j] + rhs.mData[i][j];
        }
    }
    return result;
}

/*矩阵减法“-”运算符重载*/
TransformMatrix TransformMatrix::operator - ( const TransformMatrix &rhs )
{
    TransformMatrix result;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            result.mData[i][j] = mData[i][j] - rhs.mData[i][j];
        }
    }
    return result;
}

/*矩阵乘法“*”运算符重载*/
TransformMatrix TransformMatrix::operator * ( const TransformMatrix &rhs )    //运算符*重载实现矩阵乘法
{
    TransformMatrix result;


    for( int i = 0; i < 4; ++i )
    {
        for( int j = 0; j < 4; ++j )
        {
            float rowCol = 0.0;
            for( int k = 0; k < 4; ++k )
            {
                rowCol += mData[i][k] * rhs.mData[k][j];
            }
            result.mData[i][j] = rowCol;
        }
    }
    return result;
}

/*变换矩阵求逆--根据变换矩阵性质的公式计算*/
TransformMatrix TransformMatrix::Invert()
{
    TransformMatrix result;       //新建一个临时的对象，将原对象的mData赋给它，以不改变原对象
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            result.mData[i][j] = mData[i][j];
    }

    // Exploit the fact that we are dealing with a rotation matrix + translation component.
    float   tmp = 0;
    float   vals[3] = {0};

    // Transpose left-upper 3x3 (rotation) sub-matrix--用了转换矩阵的性质，R的逆等于R的转置（正交阵）
    tmp = result.mData[0][1]; result.mData[0][1] = result.mData[1][0]; result.mData[1][0] = tmp;
    tmp = result.mData[0][2]; result.mData[0][2] = result.mData[2][0]; result.mData[2][0] = tmp;
    tmp = result.mData[1][2]; result.mData[1][2] = result.mData[2][1]; result.mData[2][1] = tmp;

    // Multiply translation component (last column) by negative inverse of upper-left 3x3.
    for( int i = 0; i < 3; ++i )
    {
        for( int j = 0; j < 3; ++j)
        {
            vals[i] += -result.mData[i][j] * result.mData[j][3];      //根据变换矩阵求逆的公式，求解逆矩阵第四列
        }
    }
    for( int i = 0; i < 3; i++ )
    {
        result.mData[i][3] = vals[i];
    }
    return result;
}

/*显示矩阵*/
void TransformMatrix::display()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            cout<<mData[i][j]<<"    ";
        cout<<endl;
    }
    cout<<endl;
}

#endif // MATRIX_CLASS_H_INCLUDED
