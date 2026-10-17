#include <iostream>
using namespace std;

// int main()
// {
//     int a = 10;
//     int &b = a;
//     cout<<a<<endl<<b<<endl;
//     b = 100;
//     cout<<a<<endl<<b<<endl;
//     return 0;
// }

void swap01(int a1,int b1)
{
    int temp = a1;
    a1 = b1;
    b1 = temp;
    cout<<a1<<" "<<b1<<endl;
}

void swap02(int * a2,int * b2)
{
    int temp = *a2;
    *a2 = *b2;
    *b2 = temp;
    cout<<*a2<<" "<<*b2<<endl;
}

void swap03(int &a3,int &b3)
{
    int temp = a3;
    a3 = b3;
    b3 = temp;
    cout<<a3<<" "<<b3<<endl;
}

int main()
{
    int a = 10;
    int b = 20;
    //swap01(a, b);
    //swap02(&a,&b);
    swap03(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}