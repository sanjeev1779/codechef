/*
Author :  ARVIND PANDEY
 */
#include <bits/stdc++.h>
using namespace std;

struct _ {
    ios_base::Init i;

    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
} _;

#define FOR(i,n) for(i=0;i<n;i++)
#define pb(x) push_back(x)
#define ll long long
#define mod 1000000

long long power(long long a, long long n)//////O(log n)
{
    long long ans = 1;
    while (n) {
        if (n % 2 == 1)
            ans *= a;
        a *= a;
        n /= 2;
    }
    return ans;
}

long long gcd(long long a, long long b)////O(log(a+b))
{
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll mulmod(ll a, ll b)
 {
    ll res = 0;
    while (a != 0) {
        if (a & 1) res = (res + b) % mod;
        a >>= 1;
        b = (b << 1) % mod;
    }
    return res;
}
int hash[1000005];
ll str[3000005];
ll temp=0,temp1,temp2;
void sorting(int n)
{
    int i,j;
    temp1=0,temp2=0;
    int cnt=0;
    FOR(i,1000005)
    {
        if(hash[i]>0)
        FOR(j,hash[i])
        {
             if(cnt%2==0)
                temp1+=i;
            else
                temp2+=i;
            cnt++;
        }
    }
    ll ans;
        if(temp1>temp2)
            ans=temp1-temp2;
        else
            ans=temp2-temp1;
        cout<<ans<<"\n";
}
////////////////////////////////////////////////////////////////////////////////////CODE BEGINS/////////////////////////////////////////////////////////

int main() {
    int t,i;
    cin>>t;
    while(t--)
    {
       int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;

        str[0]=d;
        memset(hash,0,sizeof hash);
         hash[d]++;
        for(i=1;i<n;i++)
        {
            temp=str[i-1]*str[i-1];
            temp1=temp*a;
            temp2=str[i-1]*b;
            str[i]=((temp1)+(temp2)+(c))%mod;
             hash[str[i]]++;
        }
        sorting(n);
    }
    return 0;
}
