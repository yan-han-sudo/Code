#include <iostream>
using namespace std;

//继承
class basePage
{
public:
    void header()
    {
        cout<<"公共头部"<<endl;
    }
    void footer()
    {
        cout<<"公共底部"<<endl;
    }
};

class java : public basePage
{
public:
    void content()
    {
        cout<<"java"<<endl;
    }
};

class python : public basePage
{
public:
    void content()
    {
        cout<<"python"<<endl;
    }
};

void test01()
{
    java ja;
    ja.footer();
    python py;
    py.header();
}

int main()
{
    test01();
    return 0;
}