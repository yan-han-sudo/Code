#include <iostream>
using namespace std;

class person
{
public:
    int age;

    void showClassName()
    {
        cout<<"person"<<endl;
    }

    void showAge()
    {
        if(this == nullptr)
            return;
        cout<<this->age<<endl;  //防止传入的this为空指针
    }
};

void test01()
{
    person * p = nullptr;

    p->showClassName();
    p->showAge();
}

int main()
{
    test01();
    return 0;
}