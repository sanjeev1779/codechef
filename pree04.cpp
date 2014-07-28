#include<iostream>
#include<stdio.h>
#define LL long long
#define S(N) scanf("%d",&N);
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    LL N, freq[63], skill[63];
    int i,j;
    LL G, can_inc, total_inc,diff;
    LL further_inc, actual_inc;
    while(test_cases--)
    {
        scanf("%lld",&N);
        further_inc=0;
        actual_inc=0;
        for(i=1;i<=N;i++)
        {
            scanf("%lld",&freq[i]);
        }
        for(i=1;i<=N;i++)
        {
            scanf("%lld",&skill[i]);
        }
        scanf("%lld",&G);

        for(i=1;i<=N;i++)
        {
            actual_inc+= freq[i]*skill[i];
        }

        for(i=N;i>=1&& G>0;i--)
        {
            diff=N-skill[i];
            if(diff>0)
            {
                can_inc= freq[i]*diff;
                if(can_inc<G)
                {
                    further_inc+= can_inc;
                    G-=  can_inc;
                }
                else
                {
                    further_inc+= G;
                    G=0;
                }
            }
        }
        total_inc= actual_inc+  further_inc;
        printf("%lld\n",total_inc);

    }


return 0;
}
