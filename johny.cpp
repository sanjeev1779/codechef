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
#define mp make_pair
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    int i,N,K;
    LL a[105],temp; a[0]=0;
    while(test_cases--)
    {
        S(N);
        for(i=1;i<=N;i++)
        {
                scanf("%lld",&a[i]);
        }
         cin>>K;
        temp= a[K];
        sort(a,a+N+1);

        for(i=1;i<=N;i++)
        {
            if(a[i]==temp)
            {
                printf("%d\n",i);
                break;
            }
        }
    }


return 0;
}
