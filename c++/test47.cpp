#include <iostream>
using namespace std;

class base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;  //私有对象被隐藏，但也会继承
};

class son : public base
{
public:
    int m_d;
};

void test01()
{
    cout<<sizeof(son)<<endl;
}

int main()
{
    test01();
    return 0;
}