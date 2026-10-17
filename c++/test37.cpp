#include <iostream>
#include <string>
using namespace std;

class building;

class goodGuy
{
public:
    goodGuy();

    void visit();
    void visit2();

    building * build;
};

class building
{
    friend void goodGuy::visit();

public:
    string m_sitRoom;

    building();

private:
    string m_bedRoom;
};

building::building()
{
    m_sitRoom = "客厅";
    m_bedRoom = "卧室";
}

goodGuy::goodGuy()
{
    build = new building;
}

void goodGuy::visit()
{
    cout<<build->m_sitRoom<<endl;
    cout<<build->m_bedRoom<<endl;
}

void goodGuy::visit2()
{
    cout<<build->m_sitRoom<<endl;
}

void test01()
{
    goodGuy gg;
    gg.visit();
}

int main()
{
    test01();
    return 0;
}