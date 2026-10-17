#include <iostream>
#include <string>
using namespace std;

//重载()
class myPrint
{
public:
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

class myAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }
};

void my02(string test)
{
    cout<<test<<endl;
}

void test01()
{
    myPrint my;
    my("hello");  //用的时候很像函数，仿函数
    my02("hello");
}

void test02()
{
    myAdd my;
    cout<<my(2,3)<<endl;
    cout<<myAdd()(200,20)<<endl; //匿名对象+仿函数
}

int main()
{
    test02();
    return 0;
}