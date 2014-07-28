#include<iostream>
#include<string>

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
    int t,n;
    t=fastread();
    while(t--)
    {
        n=fastread();
        if(n%2==0)
            cout<<"ALICE\n";
        else cout<<"BOB\n";
    }

return 0;
}
