#include <iostream>
using namespace std;

//声明和实现只能有一个默认参数
int triPlus(int a,int b=30,int c=20); //从有默认值的参数向右的所有参数都必须有默认值

int main()
{
    cout<<triPlus(20)<<endl;
    return 0;
}

int triPlus(int a,int b,int c)
{
    return a+b+c;
}