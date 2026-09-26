#include <iostream>
using namespace std;

#define log(x) cout<<x<<endl;

class player //定义了一个类类型的变量==对象
{
public:
    int x,y;
    int speed;

    void move(int xa,int ya)
    {
        x += xa*speed;
        y += ya*speed;
    }
};

int main()
{
    player ply; //对象的变量==实例
    ply.speed = 10;
    ply.x = 5;
    ply.y = 4;
    ply.move(1,-1);
    log(ply.x);
    log(ply.y);
    return 0;
}