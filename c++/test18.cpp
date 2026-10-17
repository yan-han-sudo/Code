#include <iostream>
using namespace std;

//引用 = 指针常量
//int &b = int a 等价于 int * const b = &a

// int & test01()
// {
//     int a = 10;
//     return a;   //不要返回局部变量/局部变量引用，会报错
// }

int & test02()
{
    static int a = 10;  //静态变量
    return a;
}

int main()
{
    int &b = test02();  //a,b在同一内存
    cout<<b<<endl;
    test02() = 1000;    //若函数返回值是引用，该函数可作为左值
    cout<<b<<endl;
    return 0;
}