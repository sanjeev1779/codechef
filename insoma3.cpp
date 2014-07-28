#include<stdio.h>
#include<iostream>
using namespace std;
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


main()
{
    int n;
    n=fastread();
    int a[n];
    int ans=0,i,j;
    for(i=0;i<n;i++)
      a[i]=fastread();

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
             ans++;
            }
        }
    }
    cout<<ans;

return 0;
}
