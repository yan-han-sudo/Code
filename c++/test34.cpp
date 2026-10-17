#include <iostream>
using namespace std;

class person
{
public:
    int a;
    mutable int b;

    //常函数
    //this为指针常量，指向不可改，值可改
    //在成员函数后加const，修饰this，让this指向不可改
    void showName() const 
    {
        //this->nullptr;
        //this->a = 10;
        this->b = 20;
    }

    void func()
    {
        a = 200;
    }
};

void test01()
{
    person p;
    p.showName();
}

void test02()
{
    //常对象
    //常对象只能调用常函数，因为普通成员函数可以修改成员属性
    //成员属性 = 成员函数 + 成员变量
    const person p{};
    p.b = 100;
    cout<<p.b<<endl;
}

int main()
{
    test02();
    return 0;
}