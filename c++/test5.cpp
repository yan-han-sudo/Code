#include <iostream>
using namespace std;

struct Entity
{
    static int x,y;

    static void Print()
    {
        cout<<x<<","<<y<<endl;
    }
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e1;
    e1.x = 5;
    e1.y = 8;

    e.Print();
    e1.Print();
    return 0;
}