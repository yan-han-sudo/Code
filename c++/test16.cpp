#include <iostream>
using namespace std;

// int * func()
// {
//     int * p = new int(10);  //指针p在栈区,数据10在堆区
//     return p;
// }

// int main()
// {
//     int * a = func();
//     cout<<*a<<endl;
//     cout<<*a<<endl;
//     cout<<*a<<endl;
//     return 0;
// }

float * func()
{
    float * p = new float(10.01);
    return p;
}

void test01()
{
    float * a = func();
    cout<<*a<<endl;
    cout<<*a<<endl;
    cout<<*a<<endl;
    delete a;
    cout<<*a<<endl; //内存被释放，再访问就非法
}

void test02()
{
    int * arr = new int[10];
    for(int i=0;i<10;i++)
    {
        arr[i] = i+10;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    // for(int i=0;i<10;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
}

int main()
{
    // test01();
    test02();
    return 0;
}