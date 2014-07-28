#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main()
{
    int N;
    int T;
    scanf("%d",&T);
    while(T--)
    {
            scanf("%d",&N);
            vll dt;
            dt.reserve(N*2);
            for (int q=0;q<N;++q)
            {
                ll x;
                scanf("%lld",&x);
                dt.push_back(x);
            }
            sort( dt.rbegin(), dt.rend() );
            ll sig = 1;
            while (sig <= dt[0])
               {
                    sig<<=1;
               }
            sig>>=1;
            for (int st = 0;sig>=1;sig>>=1)
            {
                int i = st;
                while (i<N && (dt[i]&sig)==0)
                    i++;
                if (i>=N) continue;
                swap( dt[st], dt[i] );

                for (int j=0;j<N;++j)
                    if (j!=st && (dt[j]&sig)!=0)
                        dt[j] ^= dt[st];
                st++;
            }
            ll ret = 0;
            for (int q=0;q<N;++q)
                ret ^= dt[q];
            printf("%lld\n",ret);
    }
    return 0;
}
