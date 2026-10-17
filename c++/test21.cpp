#include <iostream>
using namespace std;

void func(int a,int = 10)  //占位参数
{
    cout<<"aaa"<<endl;
}

int main()
{
    func(10);
    return 0;
}