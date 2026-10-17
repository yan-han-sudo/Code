#include <stdio.h>

int main()
{
    char in[5],out[5];
    for(int i=0;i<5;i++)
    {
        scanf("%c",&in[i]);
        out[i] = in[i] + 4;
    }
    for(int i=0;i<5;i++)
    {
        printf("%c",out[i]);
    }
    printf("\n");
    return 0;
}