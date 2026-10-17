#include <iostream>
using namespace std;

class person
{
public:
    int a;
    static int b;  //静态成员变量不属于类的对象

    void func()  //非静态成员函数不属于类的对象
    {

    }
};

int person::b = 0;

void test01()
{
    person p;
    cout<<sizeof(p)<<endl;  //空对象占一个字节
}

void test02()
{
    person p;
    cout<<sizeof(p)<<endl;
}

int main()
{
    test02();
    return 0;
}