#include <iostream>
using namespace std;

class person
{
public:
    int age;

    person(int age)
    {
        //this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    person& addAge(person &p)
    {
        this->age += p.age;  //this指向p2
        return *this;
    }
};

void test01()
{
    person p1(18);
    cout<<p1.age<<endl;
}

void test02()
{
    person p1(10);
    person p2(20);
    //链式编程
    p2.addAge(p1).addAge(p1).addAge(p1);
    cout<<p2.age<<endl;
}

int main()
{
    test02();
    return 0;
}