#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int * p;
    p = &a; //&为取址符号
    *p = 1000;  //解引用
    cout<<a<<endl;
    return 0;
}

// int main()
// {
//     int a = 10;
//     int * p = &a;
//     cout<<sizeof(p)<<endl;
//     cout<<sizeof(int *)<<endl;
//     cout<<sizeof(float *)<<endl;
//     cout<<sizeof(double *)<<endl;
//     cout<<sizeof(char *)<<endl;
//     return 0;
// }

// int main()
// {
//     int * p = nullptr; //0~255内存编号是系统占用的，不可访问
//     //int * p = NULL;
//     cout<<*p<<endl;
//     return 0;
// }

// int main()
// {
//     int * p = (int *)0x1100;
//     cout<<*p<<endl;
//     return 0;
// }