#include <iostream>
using namespace std;

class person
{
public: 
    static int a;
    int b;

    person(int A)
    {
        a = A;
    }

    static void func()  //静态成员函数
    {
        a = 2000;
        //b = 10;
        cout<<"static void func"<<endl;
    }
};

int person:: a = 100;  //静态成员变量：类内声明，类外初始化

void test01()
{
    person per(10);  //通过对象访问
    cout<<per.a<<endl;
    person p(20);
    cout<<p.a<<endl;
}

void test02()
{
    cout<<person::a<<endl;  //通过类名访问
    //cout<<person::b<<endl;
}

void test03()
{
    person p(10);  //通过对象访问
    p.func();

    person::func();  //通过类名访问
}

int main()
{
    test03();
    return 0;
}