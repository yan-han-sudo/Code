#include <iostream>
using namespace std;

class person
{
public:
    int A,B,C;

    // //传统有参构造函数初始化
    // person(int a,int b,int c)
    // {
    //     A = a;
    //     B = b;
    //     C = c;
    // }

    //初始化列表赋初值
    person(int a,int b,int c):A(a),B(b),C(c)
    {

    }
};

void test01()
{
    person p(1,2,3);
    cout<<p.A<<" "<<p.B<<" "<<p.C<<endl;
}

int main()
{
    test01();
    return 0;
}