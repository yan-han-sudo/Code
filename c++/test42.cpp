#include <iostream>
#include <string>
using namespace std;

//重载判断符号
class person
{
public:
    int m_age;
    string m_name;

    person(int age,string name)
    {
        m_name = name;
        m_age = age;
    }

    bool operator==(person const &p)
    {
        if(p.m_age == this->m_age && p.m_name == this->m_name)
            return 1;
        else
            return 0;
    }

    bool operator!=(person const &p)
    {
        if(p.m_age == this->m_age && p.m_name == this->m_name)
            return 0;
        else
            return 1;
    }
};

void test01()
{
    person p1(17,"tom");
    person p2(18,"tom");
    
    if(p1 != p2)
    {
        cout<<"不相等"<<endl;
    }
    else
    {
        cout<<"相等"<<endl;
    }
}

int main()
{
    test01();
    return 0;
}