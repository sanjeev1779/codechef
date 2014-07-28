#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<climits>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int a[100],n;
int ans=INT_MAX;
void dp(int ans,int step,int index)
{
    cout<<"hi\n";
    if(index==n+1){
            cout<<"reached\n";
        ans= min(ans,step);
        cout<<"ans ="<<ans<<endl;
        return;
    }
    if(a[index]+index<=n)
    {
        step++;
        cout<<"steps :"<<step<<endl;
        dp(ans,step,index+a[index]);
    }
    if(index-a[index]>=1)
    {
        cout<<"left\n";
        step++;
        dp(ans,step,index-a[index]);
    }
}

main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i];
    dp(ans,0,1);
    cout<<ans<<endl;

return 0;
}

