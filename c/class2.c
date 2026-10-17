#include <stdio.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    int numlist[T];
    for(int i=0;i<T;i++)
    {

        int sum=0,num=0;
        scanf("%d",&n);
        int list[n];
        for(int j=0;j<n;j++)
        {
            int weight;
            scanf("%d",&list[j]);
            sum += list[j];
        }
        int average = sum/n;
        for(int j=0;j<n;j++)
        {
            if(list[j]>average)
                num++;
        }
        numlist[i] = num;
    }
    for(int i=0;i<T;i++)
    {
        printf("%d\n",numlist[i]);
    }
    return 0;
}