#include <iostream>
using namespace std;

void showValue(const int &val)  //常量引用
{
    cout<<val<<endl;
    //val = 1000;
}

int main()
{
    // //等价于
    // //int temp = 10;
    // //int & a = temp; 
    // const int & a = 10;
    int a = 100;
    showValue(a);
    cout<<a<<endl;
    return 0;
}