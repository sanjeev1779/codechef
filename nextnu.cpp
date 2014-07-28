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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

LL fact[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};
main()
{
    int t,i,j,y,cnt,x,l;
    S(t);

    LL ans;
    string str;
    while(t--)
    {
        int a[10]={0};
        cin>>str;
        ans=0;
        l= str.size();
        for(i=0;i<l;i++)
        {
            a[str[i]-'0']++;
        }
        for(i=0;i<l;i++)
        {
            LL deno=1;
            for(int j=0;j<(str[i]-'0');j++)
            {
                if(a[j]!=0)
                {
                    for(int k=0;k<10;k++)
                    {
                        if(a[k]!=a[j]&&a[k]!=0)
                            deno*=fact[a[k]];

                    }
                    cout<<str[i]<<" "<<j<<" "<<fact[l-i-1]/deno<<endl;
                    ans+=fact[l-i-1]/deno;
                }
            }

    }
    cout<<ans<<endl;
    }
return 0;
}
