#include<iostream>
using namespace std;

inline int fastread()
    {
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;){p=getchar_unlocked();};
    while(p>32)
    {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p=getchar_unlocked();
    }
    return noRead;
    };


main()
{
    int test_cases,G,I,Q;
    long long int N,ans;
    test_cases=fastread();
    while(test_cases--)
    {
        G=fastread();
        while(G--)
        {
            I=fastread();
            N=fastread();
            Q=fastread();
            if(Q==I)
            {
                ans=N/2;
                cout<<ans<<endl;
            }
            else
            {
                ans=N-N/2;
                cout<<ans<<endl;
            }
        }
    }

return 0;
}
