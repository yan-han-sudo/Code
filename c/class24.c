#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sel;
    scanf("%c",&sel);
    printf("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\n");
    if(sel == 'A')
        printf("data is added\n");
    else if(sel == 'D')
        printf("data is deleted\n");
    else if(sel == 'S')
        printf("data is sorted\n");
    else if(sel == 'Q')
        exit(0);
    return 0;
}