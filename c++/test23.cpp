#include <iostream>
using namespace std;

const double pi = 3.1415926;

class circle
{
public:
    double r;  //属性
    double calculate()  //行为
    {
        return 2*pi*r;
    }
};

int main()
{
    circle cir;  //通过一个类实例化一个对象
    cir.r = 10.2;
    cout<<cir.calculate()<<endl;
    circle cir2;  //通过一个类实例化一个对象
    cir2.r = 22.76;
    cout<<cir2.calculate()<<endl;
    return 0;
}