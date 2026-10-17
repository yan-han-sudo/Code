#include <iostream>
using namespace std;

//只能用全局函数重载左移运算符
class person
{
    friend ostream & operator<<(ostream &out,person &p);
public:
    person(int a,int b)
    {
        m_a = a;
        m_b = b;
    }
private:
    int m_a,m_b;
};

ostream & operator<<(ostream &out,person &p)  //operater<<(cout,p)
{
    out<<p.m_a<<" "<<p.m_b;
    return out;
}

void test01()
{
    person p(10,10);

    //链式编程
    cout<<p<<" hello"<<endl;
}

int main()
{
    test01();
    return 0;
}