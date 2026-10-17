#include <iostream>
using namespace std;

int main()
{
    //const修饰指针 = 常量指针
    int a1 = 10;
    int b1 = 10;
    const int * p1 = &a1;
    p1 = &b1; //指向可改
    //*p = 20;    //值不可改

    //const修饰指针 = 指针常量
    int a2 = 10;
    int b2 = 10;
    int * const p2 = &a2;
    //p2 = &b2; //指向不可改
    *p2 = 20;    //值可改

    //const修饰指针 = 常量指针常量
    int a3 = 10;
    int b3 = 10;
    const int * const p3 = &a3;
    //p3 = &b3; //指向不可改
    //*p3 = 20;    //值不可改

    cout<<*p1<<endl;

    return 0;
}