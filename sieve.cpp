#include <iostream>
#include<cstdio>
#include <vector>
#include <math.h>
using namespace std;
int main()
{

    long long limit;
    //cin>>limit;
    limit= 1000000;
    long long sqrtlimit = sqrt(limit);
    vector<bool> sieve(limit+1, false);
int    ans=0;
    for (int n=4;n<=limit;n=n+2)
    {
        sieve[n]=true;
    }
    for(int n=3;n<sqrtlimit;n=n+2)
    {
        if(!sieve[n])
        {
            for(int m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true;
            }
        }
    }
    for(int i=2;i<=limit;i++)
    {
        if(!sieve[i]) //if sieve[i]=0
           {
               ans++;

           }
    }
    cout<<ans<<endl;

    return 0;
}
