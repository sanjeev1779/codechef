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
main()
{
    LL N,i;
    int test_cases;
    S(test_cases);
    long int tax[100];
    while(test_cases--)
    {
        scanf("%d %d %d %d %lld",&initTax,&slot1,&slot2,&K,&N);
        tax[1]=initTax;
        for(i=2;i<=slot1+1;i++)
            tax[i]=tax[i-1]+1;
        for(i=slot1+2;i<=slot1+slot2+1;i++)
            tax[i]=tax[i-1]*2;
        for(i=)
        {
            tax[slot1+slot2+3]=;
        }
        for(i=slot1+slot2+2;i<=N;i++)
        {

        }
    }

return 0;
}
