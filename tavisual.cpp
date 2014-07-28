#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
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
    int test_cases,n,c,q,l,r;

    test_cases=fastread();
    while(test_cases--)
    {
        n=fastread();
        c=fastread();
        q=fastread();

        while(q--)
        {
            l=fastread();
            r=fastread();
            //l+x=c
            //x=c-l;
            //c=r+l-c;
            if(l<=c && r>=c) // then it flips otherwise no effect
                c=r+l-c;
        }
        cout<<c<<endl;
    }
return 0;
}
