#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
int limit=  1000005;
int sqrtlimit = sqrt(limit);
vector<bool> sieve(limit+1, false);
int n,i;
void  sieve_algo()
{

    sieve[0]=true;
    sieve[1]=true;
    for (n=4;n<=limit;n=n+2)
        sieve[n]=true;

    for(n=3;n<sqrtlimit;n=n+2)
    {
        if(!sieve[n])
        {
            for(int m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true;
            }
        }
    }
}
main()
{
    sieve_algo();
    int t;
    LL P;
    S(t);
    double x;
    while(t--)
    {
        scanf("%lld",&P);

        x= sqrt(P);
        if(x==(int)x)
        {
            x=(int)x;
            if(sieve[x]==false)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }

return 0;
}
