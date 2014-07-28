#include<stdio.h>
#include<math.h>

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
	int t,n,i,ans,minm;
	t=fastread();
	while(t--)
	{
		n=fastread();
		minm=n-1;
		int ran= sqrt(n)+1;
		for(i=2;i<=ran;i++)
		{
			if(n%i==0) //I IS WIDTH
			{
				ans=abs(n/i-i);
				if(ans<=minm)
				{
					minm=ans;
				}
			}
		}
		printf("%d\n",minm);
	}

return 0;
}
