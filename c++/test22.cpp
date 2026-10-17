#include <iostream>
using namespace std;

//函数重载
void func(double a)
{
    cout<<"aaa"<<endl;
}

void func(int a,int b)
{
    cout<<"int(a)"<<endl;
}

void func(double a,int b)
{
    cout<<"a+b"<<endl;
}

void func(int a,double b)
{
    cout<<"b+a"<<endl;
}

void func(int &a)
{
    cout<<"引用"<<endl;
}

void func(const int &a)
{
    cout<<"常量引用"<<endl;
}

//注意:函数重载碰到默认参数

int main()
{
    func(10);
    return 0;
}