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
    int test_cases;
    LL p,q;
    S(test_cases);
    while(test_cases--)
    {
        scanf("%lld %lld",&p,&q);
        if((p-q)%2==0)
            printf("B\n");
        else
            printf("A\n");
    }
return 0;
}
