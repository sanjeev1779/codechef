#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,n;
    int cnt=0;
    for(i=0;i<1000;i++)
    {
        int a= randomize(100);
       // cout<<a<<"\n";
        if(a%2==0)
         cnt++;
    }
    printf("%d\n",cnt);
}
