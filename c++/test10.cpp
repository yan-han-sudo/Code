#include <iostream>
using namespace std;

void swap01(int * p1,int * p2)  //地址传递
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout<<"swap01: "<<*p1<<" "<<*p2<<endl;
}

void swap02(int a,int b)    //值传递
{
    int temp = a;
    a = b;
    b = temp;
    cout<<"swap02: "<<a<<" "<<b<<endl;
}

int main()
{
    int a,b;
    cin>>a>>b;
    swap01(&a,&b);
    //swap02(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}