#include <iostream>
using namespace std;

//赋值运算符重载
class person
{
public:
    int * m_age;
    
    person(int a)
    {
        m_age = new int(a);
    }

    ~person()
    {
        if(m_age != nullptr)
        {
            delete m_age;
            m_age = nullptr;
        }
    }

    person& operator=(const person &p) //赋值不改变右侧对象
    {
        //先判断并释放堆区属性
        if(m_age != nullptr)
        {
            delete m_age;
            m_age = nullptr;
        }
        // m_age = p.m_age;  //浅拷贝
        m_age = new int(*p.m_age);  //深拷贝
        return *this;
    }
};

void test01()
{
    person p1(18);
    person p2(10);
    person p3(1);
    p3 = p2 = p1;
    cout<<*p1.m_age<<endl;
    cout<<*p2.m_age<<endl;
    cout<<*p3.m_age<<endl;
}

int main()
{
    test01();
    return 0;
}