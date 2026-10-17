#include <iostream>
using namespace std;

//子类父类成员同名
class base
{
public:
    int static m_a;

    void static func()
    {
        cout<<"base"<<endl;
    }

    void static func(int)
    {
        cout<<"base_int"<<endl;
    }
};

int base::m_a = 10;

class son : public base
{
public:
    int static m_a;

    void static func()
    {
        cout<<"son"<<endl;
    }
};

int son::m_a = 1000;

void test01()
{
    son s;
    cout<<s.base::m_a<<endl;
    cout<<son::base::m_a<<endl;

    s.base::func();
    son::base::func();
    son::base::func(2);
}

int main()
{
    test01();
    return 0;
}