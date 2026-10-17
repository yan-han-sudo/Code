#include <iostream>
#include <string>
using namespace std;

class building
{
    //goodGuy类可以访问building类中的私有成员
    friend class goodGuy;

public:
    string m_sitRoom;

    building();  //构造函数声明

private:
    string m_bedRoom;
};

//类外写无参构造函数
building::building()
{
    m_sitRoom = "客厅";
    m_bedRoom = "卧室";
}

class goodGuy
{
public:

    goodGuy();  //构造函数声明

    void visit();  //成员函数声明

    building * build;
};

goodGuy::goodGuy()
{
    //将指针build指向building中的成员
    build = new building;
}

void goodGuy::visit()
{
    cout<<build->m_sitRoom<<endl;
    cout<<build->m_bedRoom<<endl;
}

void test01()
{
    goodGuy goo;
    goo.visit();
}

int main()
{
    test01();
    return 0;
}