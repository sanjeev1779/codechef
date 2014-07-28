#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int test_cases,i,k,l;
    char ch[1005];
    scanf("%d",&test_cases);
    getchar();
    int a[8];
    for(k=1;k<=test_cases;k++)
    {
        gets(ch);
        l= strlen(ch);
        memset(a,0,sizeof(a));
        for(i=0;i<l;i++)
        {
            if(ch[i]=='H')
                a[0]++;
            else if(ch[i]=='A')
                a[1]++;
            else if(ch[i]=='C')
                a[2]++;
            else if(ch[i]=='K')
                a[3]++;
            else if(ch[i]=='E')
                a[4]++;
            else if(ch[i]=='R')
                a[5]++;
            else if(ch[i]=='U')
                a[6]++;
            else if(ch[i]=='P')
                a[7]++;

        }
        a[2]=a[2]/2;
        sort(a,a+8);
        printf("Case #%d: %d\n",k,a[0]);
    }

return 0;
}
