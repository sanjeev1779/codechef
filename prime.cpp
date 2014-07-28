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
int x;
int limit=  x+2;
int sqrtlimit = sqrt(limit);
vector<bool> sieve(limit+1, false);
int n,i;
void  sieve_algo()
{
    sum=0;

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
    for(i=0;i<=x;i++)
    {
        if(!sieve[i])
        {
            sum+=i;
            P(i);
        }

    }
    printf("%lld\n",sum);

}
main()
{

    cin>>x;
    sieve_algo();


return 0;
}
