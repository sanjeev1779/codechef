#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    long long C;
    LL f,s,last_end;
    int i,ans;
    while(test_cases--)
    {
        scanf("%lld",&C);
        ans=1;
        pair<LL,LL>p[C+1];
        for(i=0;i<C;i++)
        {
            scanf("%d %d",&s,&f);
            p[i]= mp(f,s);
        }
        sort(p,p+C);
        last_end= p[0].first;
       // cout<<"l= "<<last_end<<endl;
        for(i=1;i<C;i++)
        {
            if(p[i].second>=last_end) // add it
            {
                last_end= p[i].first;
               // cout<<"l= "<<last_end<<endl;
                ans++;
            }
        }
        P(ans);
    }
return 0;
}
