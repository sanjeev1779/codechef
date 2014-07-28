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
LL mod=1000000007;
inline void fastLongInput(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
            neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}
LL bin(int n)
{
    LL bn=0,pow=1;
    int rem;
    while(n>0)
    {
        rem=n%2;
        bn+=rem*pow;
        pow=pow*10;
        n/=2;
    }
    return bn;
}




main()
{
     std::ios_base::sync_with_stdio(0);
    LL ten_powers[]={2, 1024, 976371285, 688423210, 905611805, 607723520, 235042059, 255718402, 494499948, 140625001, 291251492, 25600497, 959366170, 836339738, 621966918, 264444359, 271283348, 952065854, 719476260, 28918236, 855473248, 741583475};
    int i,test_cases,rem,n;
    LL ans;
    S(test_cases);
    while(test_cases--)
    {
        //fastLongInput(n);
        cin>>n;
        ans=1;
        i=0;
        while(n>0)
        {
            rem=n%2;
            n=n>>1;
            if(rem)
            {
                ans=(ans*ten_powers[i])%mod;
            }
            i++;
        }
       // printf("%lld\n",(ans*ans)%mod);
    cout<<(ans*ans)%mod<<endl;
    }
return 0;
}
