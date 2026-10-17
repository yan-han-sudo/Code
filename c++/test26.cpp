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

void test01()
{
    person p1(20);
    person p2(p1);
    cout<<p2.age<<endl;
}

//值的方式传值
void doWork(person p)
{

}

void test02()
{
    person per;
    doWork(per);
}

//值的方式返回值
person doWork2()
{
    static person per;
    cout<<(int*)&per<<endl;
    return per;
}

void test03()
{
    person p = doWork2();
    cout<<(int*)&p<<endl;
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}