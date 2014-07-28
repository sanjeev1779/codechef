#include<stdio.h>
#define ULL unsigned long long

ULL gcd(ULL a,ULL b)
{
	ULL c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}

ULL spoons(ULL n, ULL k)
{
    ULL c=1,g,i;
    if(k>n)
        return 0;
    if(k>n-k)
      k=n-k;
   for(i=1;i<=k;i++)
   {
        g=gcd(c,i);
        c=c/g;
        c*= (n-i+1)/(i/g);
   }
   return c;
}


main()
{
    ULL n,r;
    int i;
    int test_Cases;
    ULL ans[70];
    for(i=4;i<=67;i++)
    {
        ans[i]= spoons(i,i/2);
    }
        scanf("%d",&test_Cases);
    while(test_Cases--)
    {
        scanf("%lld",&n);
        if(n==2)
            printf("2\n");
        else if(n==3)
            printf("3\n");
        else
        {
            i=4;
            while(ans[i]<n)
            {
                i++;
            }
            printf("%d\n",i);
        }

    }


return 0;
}
