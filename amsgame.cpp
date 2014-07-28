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

int gcd(int a,int b)
{
    if(a%b==0)
      return b;
    else
       return gcd(b,a%b);
}

main()
{
    int test_Cases,i,j,ans,n,mini,maxi;
    test_Cases=fastread();
    while(test_Cases--)
    {
        n=fastread();
        int a[n];
        for(i=0;i<n;i++)
        {
            a[i]=fastread();
        }
        ans=gcd(a[0],a[1]);
        for(i=2;i<n;i++)
        {
            ans=gcd(a[i],ans);
        }
        printf("%d\n",ans);
    }

return 0;
}
