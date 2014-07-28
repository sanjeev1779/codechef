#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
vector<LL>vec;
int check(LL num)
{
    int rem;
    while(num>0)
    {
        rem=num%10;
        num/=10;
        if(rem==2 || rem== 3 || rem==5 || rem==6 || rem==7 || rem==8)
            return 0;
    }
    return 1;
}
void precompute()
{
    LL i;
    for(i=1;i<=100000;i++)
    {
        if(check(i*i)==1)
            {
                vec.pb(i*i);
                printf(",%lld ",i*i);
            }
    }
}
main()
{
    precompute();
return 0;
}
