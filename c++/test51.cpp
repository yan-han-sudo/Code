#include <iostream>
using namespace std;

class base1
{
public:
    int m_a = 10;
};

class base2
{
public:
    int m_a = 20;
};

class son : public base1,public base2
{
public:
    int m_a = 30;
};

void test01()
{
    son s;
    cout<<s.base2::m_a<<endl;
    cout<<sizeof(son)<<endl;
}

int main()
{
    test01();
    return 0;
}