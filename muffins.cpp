#include<stdio.h>
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
    int n,t,ans;
    t=fastread();
    while(t--)
    {
        n=fastread();
        ans=n/2+1;
        printf("%d\n",ans);
    }
return 0;
}
