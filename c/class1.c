// #include <stdio.h>
// #include "class1.h"

// int main()
// {
//     int a,b,c,sum;
//     printf("number1 = ");
//     scanf("%d",&a);
//     printf("number2 = ");
//     scanf("%d",&b); 
//     c = max(a,b);
//     printf("the maximum number is:%d\n",c);
//     return 0;
// }

// int main()
// {
//     printf("hello world\rIEEE\n");
//     return 0;
// }

// int main()
// {
//     unsigned int a = -1;
//     printf("%u\n",a);
//     return 0;
// }

// int main()
// {
//     double a = 1145.1431415926;
//     printf("%lf\n",a);
//     float b = 1145.1431415926;
//     printf("%d\n",(int)b);
//     return 0;
// }

// int main()
// {
//     int a = 0x123;
//     printf("%d\n",a);
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     char a;
//     scanf("%c",&a);
//     printf("%c\n",a);
//     return 0;
// }

#include <stdio.h>

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%d",a-b);
  printf("%d",a+b);
  printf("%d",a*b);
  printf("%d",a/b);
  return 0;
}