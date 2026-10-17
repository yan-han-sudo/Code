#include <iostream>
using namespace std;

void bubble(int * arr,int len)
{
    for(int i = len-1;i>0;i--)
    {
        int * p = arr;
        for(int j = 0;j<i;j++)
        {
            if(*p>*(p+1))
            {
                int temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
            p++;
        }
    }
}

void print(int * arr,int len)
{
    for(int i = 0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10] = {10,4,2,0,5,7,1,3,6,8};

    bubble(arr,10);
    print(arr,10);

    return 0;
}