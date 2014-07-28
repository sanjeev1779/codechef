#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define VI vector<int>
#define pb push_back
#define P(N) printf("%d\n",N)
#define S(N) scanf("%d",&N)
#define CLEAR(Arr) memset(Arr,0,sizeof(Arr))
using namespace std;
vector<int>a;
main()
{
    int n,i,x,key;
    cin>>n;
    for(i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
    cin>>key;
    int ans=upper_bound(a.begin(), a.end(),key)-lower_bound(a.begin(), a.end(),key);
    cout<<ans;

}
