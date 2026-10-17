#include <iostream>
using namespace std;

class person
{
public:
    int age;
    int * height;

public:
    person()  //无参构造函数/默认构造函数：创建对象时自动调用一次
    {
        cout<<"无参构造函数"<<endl;
    }

    person(int a)
    {
        age = a;
        cout<<"有参构造函数"<<endl;
    }

    person(const person &per) //将传入的类的属性拷贝
    {
        age = per.age;
        //new返回int(x)中x的地址
        height = new int(*per.height);  //深拷贝，将成员变量拷贝到堆区
        //height = per.height;  //浅拷贝
        cout<<height<<endl;
        cout<<"拷贝构造函数"<<endl;
    }

    person(int Age,int Height)
    {
        age = Age;
        height = new int(Height);
        cout<<height<<endl;
    }

    ~person()  //析构函数：将堆区开辟的数据释放
    {
        if(height != nullptr)
        {
            delete height;
            height = nullptr;
        }
        cout<<"析构函数"<<endl;
    }
};

void test01()
{
    person p1(18,170);  
    cout<<p1.age<<" "<<*p1.height<<endl; 
    person p2(p1);
    cout<<p2.age<<" "<<*p2.height<<endl;
}

int main()
{
    test01();
    return 0;
}