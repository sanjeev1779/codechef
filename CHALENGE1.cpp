#include<iostream>
#include<stdio.h>
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
    int t,n,h,i,temp;
    long long int score;
    //cin>>t>>n>>h;
    t=fastread();
    n=fastread();
    h=fastread();

    i=0;
    while(t--)
    {
        temp=n;
        while(temp--)
        {
            printf(i+"sanjeevkum\n");
            i++;
            i=i%3;
        }
        fflush(stdout);
        score=fastread();
    }


return 0;}
