#include <stdio.h>
#include "head.h" #包含当前目录下的头文件

int main()
{
    int a=10;
    int b=20;
    printf("a + b = %d\n",add(a,b));
    printf("a - b = %d\n",sub(a,b));
    return 0;
}