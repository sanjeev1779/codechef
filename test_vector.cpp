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
#define VI vector<int>
using namespace std;
main()
{

    vector<VI>v(100);
    int N,i,x,y;
    S(N);
    for(i=0;i<N;i++)
    {
        S(x);
        S(y);
        v[i].pb(x);
        v[i].pb(y);
    }
    sort(v.begin(), v.end());
    for(i=0;i<N;i++)
    {
        printf("%d %d\n",v[i][0], v[i][1]);
    }

return 0;
}
