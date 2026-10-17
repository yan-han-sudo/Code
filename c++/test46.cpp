#include <iostream>
using namespace std;

class base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class son1 : public base
{
public:
    void func()
    {
        m_a = 10;   //public
        m_b = 2;    //protected
        // m_c = 1; //private
    }
};

class son2 : protected base
{
public:
    void func()
    {
        m_a = 10;   //protected
        m_b = 2;    //protected
        // m_c = 1; //private
    }
};

class son3 : private base
{
public:
    void func()
    {
        m_a = 10;   //private
        m_b = 2;    //private
        // m_c = 1; //private
    }
};

class grandSon3 : public son3
{
public:
    void func()
    {
        //m_a = 10;   //private
    }

};


void test01()
{
    son1 s1;
    s1.m_a = 100;
    // s1.m_b = 20;
    // s1.m_c = 10;

    son2 s2;
    // s2.m_a = 100;
    // s2.m_b = 20;
    // s1.m_c = 10;

    son3 s3;
    // s3.m_a = 100;
    // s3.m_b = 20;
    // s1.m_c = 10;
}