#include <iostream>
#include <string>
using namespace std;

class phone
{
public:
    string p_name;

    phone(string p):p_name(p)
    {
        cout<<"phone构造函数"<<endl;
    }

    ~phone()
    {
        cout<<"phone析构函数"<<endl;
    }
};

class person
{
public:
    string name;
    phone Pname;

    person(string n,string p):name(n),Pname(p)
    {
        cout<<"person构造函数"<<endl;
    }

    ~person()
    {
        cout<<"person析构函数"<<endl;
    }
};

void test01()
{
    person per("小明","苹果");
    cout<<per.name<<" "<<per.Pname.p_name<<endl;
}

int main()
{
    test01();
    return 0;
}