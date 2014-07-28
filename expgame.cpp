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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL fast_pow(int x,int n)
{
    LL prod=1;
    LL a=x;
    while(n>0)
    {
        if(n&1)
            prod=(prod*a);
        a= (a*a);
        n=n>>1;
    }
    return prod;//%mod;
}
main()
{
    int test_cases,flag,N,i,a[102];
    S(test_cases);
    LL x;
    while(test_cases--)
    {
        S(N);
        for(i=1;i<=N;i++)
            S(a[i]);
        if(N==1)
        {
            i=1;
            flag=0;
            while(1)
            {
                x= fast_pow(i,i);
                if(a[1]==x)
                {
                    flag=1;
                    break;
                }
                if(x>a[1])
                    break;
                i++;
            }
        }
        if(flag)
            cout<<"Little Chef\n";
        else
            cout<<"Head Chef\n";
    }
return 0;
}
