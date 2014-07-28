#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
/*
inline int fastread()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};
*/
main()
{

int  n1,n2,n3,a[50005],b[50005],num,i;
    for(i=0;i<50005;i++)
    {
        a[i]=0;
    }

   // n1=fastread();
    //n2=fastread();
    //n3=fastread();
    scanf("%d %d %d",&n1,&n2,&n3);
    int total=n1+n2+n3;
    for(i=0;i<total;i++)
    {
        scanf("%d",&num);
        a[num]++;
    }
        int j=0;
        for(i=0;i<50005;i++)
        {
            if(a[i]>=2)
            {
                b[j]=i;
                j++;
            }
        }
        cout<<j<<endl;
        for(i=0;i<j;i++)
        {
            cout<<b[i]<<endl;
        }


return 0;
}
