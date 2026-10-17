#include <iostream>
#include <cstring>
using namespace std;

// int main()
// {
//     char num = 'a';
//     cout<<(int)num<<endl;
//     return 0;
// }

int main()
{
    char list[10];
    memset(list,'a',sizeof(list));
    for(int i=0;i<10;i++)
        cout<<list[i];
    return 0;
}