#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<map>
#include<cmath>
#include<algorithm>

#define For(i,a,b) for(i=a;i<b;i++)
#define ll long long int

using namespace std;
unsigned ll N=-1000000000;
vector<ll> max_left(vector<ll>arr,ll n)
{
    vector<ll>res(n);
    res[0]=arr[0];
    ll maxi=arr[0];
    for(ll i=1;i<n;i++)
    {
         maxi=max(arr[i],maxi+arr[i]);
        res[i]=max(maxi,res[i-1]);
    }
    return res;
}
vector<ll> max_right(vector<ll>arr,ll n)
{
    vector<ll>res(n);
    res[n-1]=arr[n-1];
    ll maxi=arr[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        maxi=max(arr[i],maxi+arr[i]);
        res[i]=max(maxi,res[i+1]);
    }
    return res;
}
ll ans(vector<ll>arr,ll n,ll k)
{
ll maxi=N;
vector<ll>maxleft=max_left(arr,n);
vector<ll>maxright=max_right(arr,n);
ll sum;
for(ll i=0;i<n-k-1;i++)
{
    sum=maxleft[i]+maxright[i+k+1];
   // cout<<maxleft[i]<<" "<<maxright[i+k+1]<<endl;
    maxi=max(maxi,sum);
}

return maxi;
}

 int main()
 {

     freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
ll t;
cin>>t;
    while(t--)
    {
        vector<ll>arr;   ll elem,n,k;
        cin>>n>>k;
        for(ll i=0;i<n;i++)
        {
            cin>>elem;
            arr.push_back(elem);
        }
        cout<<ans(arr,n,k)<<endl;
    }

 return 0;
 }
