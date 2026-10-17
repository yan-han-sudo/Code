#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int * p = arr;  //指针p指向arr首地址
    cout<<sizeof(p)<<endl;
    cout<<*p<<endl; //指针访问第一个元素
    p++;            //指针后移8个字节
    cout<<*p<<endl; //指针访问第一个元素

    int * p2 = arr; //指针遍历一维数组
    for(int i = 0;i<10;i++)
    {
        cout<<*p2<<" ";
        p2++;
    }
    cout<<endl;

    return 0;
}