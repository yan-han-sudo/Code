#include <iostream>
using namespace std;

//子类父类成员同名
class base
{
public:
    int m_a;
    base()
    {
        m_a = 10;
    }

    void func()
    {
        cout<<"base"<<endl;
    }

    void func(int)
    {
        cout<<"base_int"<<endl;
    }
};

class son : public base
{
public:
    int m_a = 100000;

    void func()
    {
        cout<<"son"<<endl;
    }
};

void test01()
{
    son s;
    cout<<s.base::m_a<<endl;
    s.base::func();
    //子类同名成员函数会隐藏掉父类中所有同名成员函数
    //若想访问父类被隐藏的成员函数，需加作用域
    s.base::func(2);
}

int main()
{
    test01();
    return 0;
}