#include <iostream>
using namespace std;

class animal //虚基类
{
public:
    int m_age;

    animal()
    {
        m_age = 10;
    }
};

class yang : virtual public animal //虚继承
{

};

class tuo : virtual public animal //虚继承
{

};

class yang_tuo : public yang , public tuo
{

};

void test01()
{
    yang_tuo yt;
    yt.yang::m_age = 100;
    yt.tuo::m_age = 1000;
    cout<<yt.m_age<<endl;
    cout<<sizeof(yang_tuo)<<endl;
}

int main()
{
    test01();
    return 0;
}