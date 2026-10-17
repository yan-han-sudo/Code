#include <iostream>
using namespace std;

//递增运算符重载
class myInt
{
    //const myInt&可以绑定右值，my++产生的左值也能传进去
    friend ostream & operator<<(ostream &out,const myInt &m);
public:
    myInt()
    {
        m_num = 0;
    }

    //前置递增
    //返回引用为了对统一数据递增
    myInt & operator++()
    {
        m_num++;
        return *this;  //将自身返回
    }

    //后置递增
    //int代表占位参数，用于区分前后置
    myInt operator++(int)
    {
        myInt temp = *this;
        m_num++;
        return temp;
    }

private:
    int m_num;
};

ostream & operator<<(ostream &out,const myInt &m)
{
    out<<m.m_num;
    return out;
}

void test01()
{
    myInt my;
    cout<<++(++my)<<endl;
    cout<<my<<endl;
}

void test02()
{
    myInt my;
    cout<<my++<<endl;
    cout<<my<<endl;
}

int main()
{
    test01();
    return 0;
}