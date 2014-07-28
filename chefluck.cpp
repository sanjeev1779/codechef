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
    int a,b,n,test_cases,ans,rem;
    test_cases=fastread();
    while(test_cases--)
    {
        n=fastread();
        b=0;
        int p=1;
        while(1)
        {
            rem= (n-4*b)%7;
            if(rem==0)
            {
                p=0;
                a=(n-4*b)/7;
                break;
            }
            else
            {
                 b++;
                 a=(n-4*b)/7;
                 if(a<0)
                    break;
            }
        }

        if(p==0)
        {
            ans=7*a;
            printf("%d\n",ans);
        }
        else printf("-1\n");
    }

return 0;
}
