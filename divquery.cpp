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
vector<int>fact[100001];

inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};


main()
{
    int N,Q,i,j;
    int L,R,K;
    S(N);
    S(Q);
    int x;
    int a[100001];
   for(i=0;i<N;i++)
    {
       // S(x);
       x=fastRead_int();
        for(j=1;j*j<=x;j++)
        {
            if(x%j==0)
            {
                fact[j].pb(i);
                if(j*j!=x)
                    fact[x/j].pb(i);
            }
        }
    }

    int ans=0;

    while(Q--)
    {
        /*S(L);
        S(R);
        S(K);*/
        L=fastRead_int();
        R=fastRead_int();
        K=fastRead_int();
        L--;
        R--;
        //here we have indees dat r divided by K
        // use Binary search to find the number of indexes from L to R
        ans= upper_bound(fact[K].begin(), fact[K].end(), R)- lower_bound(fact[K].begin(), fact[K].end(), L);
        P(ans);


    }

return 0;
}
