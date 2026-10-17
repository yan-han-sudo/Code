#include <iostream>
using namespace std;

//运算符重载：实现自定义数据类型的运算
class person
{
public:
    int m_a,m_b;

    // //成员函数重载
    // person operator+(person &p)
    // {
    //     person temp;
    //     temp.m_a = this->m_a + p.m_a;
    //     temp.m_b = this->m_b + p.m_b;
    //     return temp;
    // }

};

//全局函数重载
person operator+(person &p1,person &p2)
{
    person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

//运算符重载也可发生函数重载
person operator+(person &p1,int a)
{
    person temp;
    temp.m_a = p1.m_a + a;
    temp.m_b = p1.m_b + a;
    return temp;
}

void test01()
{
    person p1;
    p1.m_a = 10;
    p1.m_b = 20;
    person p2;
    p2.m_a = 30;
    p2.m_b = 40; 

    person p3 = p1 + p2;
    person p4 = p1 + 10;
    //person p3 = p1.operater+(p2);
    //person.p3 = operater+(p1,p2);

    cout<<p3.m_a<<endl;
    cout<<p3.m_b<<endl;
    cout<<p4.m_a<<endl;
    cout<<p4.m_b<<endl;
}

int main()
{
    test01();
    return 0;
}