#include <stdio.h>
#include <stdbool.h>

void manu()
{
    printf("1 计算n!\n2 输出素数\n3 判定闰年\n");
}

int prime(int n) 
{
    if(n < 2) return 0;          
    if(n == 2) return 1;        
    if(n%2 == 0) return 0;  

    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t,num,numlist[t];
    int a,out=1;
    int b,c,n=0,list[n];
    int d;
    bool result;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&num);
        numlist[i] = num;
        switch (num) 
        {
            case 1:
            {
                scanf("%d",&a);
                for(int j=a;j>0;j--)
                {
                    out *= j;
                }
                break;
            }
            case 2:
            {
                scanf("%d%d",&b,&c);
                for(int j=b;j<c;j++)
                {
                    if(prime(j)==1)
                        n++;
                }
                for(int j=b;j<c;j++)
                {
                    if(prime(j)==1)
                    {
                        list[j] = j;
                    }   
                }
                break;
            }
            case 3:
            {
                scanf("%d",&d);
                if((d%4==0&&d%100!=0)||d%400==0)
                    result = true;
                else
                    result = false;
                break;
            }
            default:
                printf("INPUT ERROR!");
                break;
        }
    }
    for(int i=0;i<t;i++)
    {
        num = numlist[i];
        switch (num)
        {
            case 1:
                manu();
                printf("%d\n",out);
                printf("\n");
                break;
            case 2:
                manu();
                for(int j=b;j<c;j++)
                {
                    if(list[j] != 0)
                        printf("%d ",list[j]);
                }
                printf("\n");
                break;
            case 3:
                manu();
                if(result == true)
                    printf("%d是闰年\n",d);
                else
                    printf("%d非闰年\n",d);
        }
        printf("\n");
    }
    return 0;
}