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


int lucky(LL num)
{
    int flag=0,rem;
    while(num>0)
    {
        rem=num%10;
        num/=10;
        if(rem==4 || rem==7)
            flag=1;
    }

    if(flag)
        return 1;
    else return 0;
}
int solve(LL num)
{
    LL i;
    int cnt=0;
    for(i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            if(lucky(i))
                cnt++;

            if(i*i!=num)
            {
                if(lucky(num/i))
                    cnt++;
            }
        }
    }

    return cnt;
}
main()
{
    int test_cases,ans;
    LL  num;
    S(test_cases);
    while(test_cases--)
    {
        scanf("%lld",&num);
        ans= solve(num);
        printf("%d\n",ans);
    }
return 0;
}
