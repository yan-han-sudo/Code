#include <iostream>
#include <string>
using namespace std;

class building
{
    //goodGuy全局函数可以访问building类中的私有成员
    friend void goodGuy(building &bui);

public:
    string m_sitRoom;

    building()
    {
        m_sitRoom = "客厅";
        m_bedRoom = "卧室";
    }

private:
    string m_bedRoom;
};

//全局函数做友元
void goodGuy(building &bui)
{
    cout<<bui.m_sitRoom<<endl;
    cout<<bui.m_bedRoom<<endl;
}

void test01()
{
    building build;
    goodGuy(build);
}

int main()
{
    test01();
    return 0;
}