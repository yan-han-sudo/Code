#include <iostream>
using namespace std;

class person
{
public:
    int age;

public:
    person()  //无参构造函数/默认构造函数：创建对象时自动调用一次
    {
        cout<<"无参构造函数"<<endl;
    }

    person(int a)
    {
        age = a;
        cout<<"有参构造函数"<<endl;
    }

    person(const person &per) //将传入的类的属性拷贝
    {
        age = per.age;
        cout<<"拷贝构造函数"<<endl;
    }

    ~person()  //析构函数：对象销毁时自动调用一次
    {
        cout<<"析构函数"<<endl;
    }
};

int main()
{
    // person per1;  //栈上的数据，main函数执行完自动销毁
    
    // //括号法调用构造函数
    // person per2(120);
    // person per3(per2);

    // //显示法调用构造函数
    // person per2 = person(10); 
    // person per3 = person(per2);

    //隐式转换法调用构造函数
    person per2 = 10;
    person per3 = per2;

    //person(10);  //匿名对象：当前执行结束后立即销毁+不用拷贝构造函数初始化匿名对象

    cout<<per3.age<<endl;

    return 0;
}