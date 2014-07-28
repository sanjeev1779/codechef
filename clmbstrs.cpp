#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define mod 1000000007
using namespace std;
LL a[1000003]={0};
int i,c;

void precompute()
{
    a[1]=1;
    a[2]=2;
    for(i=3;i<=1000001;i++)
    {
        a[i]=(a[i-1]+a[i-2])%mod;
    }
}

int d2b(LL num)
{
    LL bin= num;
    c=0;
    while(bin>0)
    {
        if(bin%2==1)
            c++;
        bin/=2;
    }
    return c;
}

main()
{
    precompute();
    int test_cases;
    int N,G,x;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        scanf("%d %d",&N,&G);
        x= d2b(a[N]);
        if(x==G)
            printf("CORRECT\n");
        else
            printf("INCORRECT\n");
    }

return 0;
}

