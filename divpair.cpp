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
    S(test_cases);
    LL n,m,full,partial;
    LL ans;
    while(test_cases--)
    {
        scanf("%lld %lld",&n,&m);
        full= n/m;
        partial= n%m;
        ans= full*full*(m-1); // we have to choose trwo nums from group of x size
        ans= ans+ full*(full-1)*1;

        if(m%2==0)
            ans=ans- full;  // repeatation removed
        ans/=2; // since a<b , so remove a>=b case


        // time for partial calculations

        ans+= full*partial;

        if(partial-m/2 >0)
            ans+= 1*(partial-m/2);
        printf("%lld\n",ans);



    }

return 0;
}
