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
    LL c1,c2,c3,c4,i;
    LL n,m;
    LL ans;
    LL bus[1005];
    LL tot_bus=0, tot_truck=0;
    LL truck[1005];
    cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    LL cost_t1_bus=0, cost_t1_truck=0;
    for(i=0;i<n;i++)
    {
        cin>>bus[i];
       cost_t1_bus+= min(bus[i]*c1,c2);
    }
    for(i=0;i<m;i++)
    {
        cin>>truck[i];
       cost_t1_truck+= min(truck[i]*c1,c2);
    }
    LL ans1 = c4;
   // LL cost_t1_bus= tot_bus*c1;
    //LL cost_t1_truck= tot_truck*c2;
    LL ans2= c3;
    ans= min( ans1, cost_t1_bus+ m*c2); // 1 2
    ans= min( ans, cost_t1_truck+cost_t1_bus); // 1 1
    ans = min( ans, cost_t1_truck + n*c2); // 2 1
    ans= min(ans, cost_t1_bus+c3); // 1 3
    ans= min( ans, n*c2 + m*c2); // 2 2
    ans= min(ans, n*c2+ c3); // 2 3
    ans= min(ans, c3+ cost_t1_truck ); // 3 1
    ans= min(ans, c3 + m*c2 );// 3 2
    ans= min(ans,2*c3); // 3 3
    cout<<ans<<endl;
    //


return 0;
}
