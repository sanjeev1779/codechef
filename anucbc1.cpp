#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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
int maxm=100005;
LL inverse_fact[100005];
LL fact[100005];
LL mod=1000000009;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}

inline void fastInput(int &x) {
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

LL fast_exp_pow(LL a, LL b, LL mod)
{
    LL prod=1;
    while(b>0)
    {
        if(b&1) prod=(prod*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return prod;

}
void precompute1()
{
    fact[0]=1;
    for(int i=1;i<maxm;i++)
    {
         fact[i]= (i*fact[i-1])%mod;
    }
}
void precompute()
{
    for(int i=0;i<maxm;i++)
    {
         inverse_fact[i]= fast_exp_pow(fact[i],1000000007,1000000009);
    }
}
main()
{
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       precompute1();
       precompute();
       int x,y,test_cases,N,Q,i,j,k,n1,n2,M;

       S(test_cases);
       int freq[102];
       int cards[100005];
       LL subset_sum[105],cbc[2][105],times;

       while(test_cases--)
       {

            S(N); S(Q);
            for(i=0;i<N;i++) S(cards[i]);

            while(Q--)
            {
                memset(cbc,0,sizeof(cbc));
                memset(freq,0,sizeof(freq));
                S(M);

               // calculate the frequency of each number modulo M
               for(i=0;i<N;i++)
               {
                   x= (cards[i]%M+M)%M;
                   freq[x]++;
               }
              // for(i=0;i<M;i++) cout<<freq[i]<<" ";
               //cout<<endl;
               // find the number of different subsets which generate from 0 to m

               n1=0;
               n2=1;
               // base case
               cbc[0][0]=1;
               for(i=0;i<M;i++)
               {

                   memset(subset_sum,0,sizeof(subset_sum));
                   for(j=0;j<=freq[i];j++)
                   {
                       x=(i*j)%M; // using number i-> j times
                       times= (fact[freq[i]]*((inverse_fact[j]*inverse_fact[freq[i]-j])%mod))%mod;
                       subset_sum[x]= times;
                   }
                    //
                    swap(n1,n2);
                    for(x=0;x<M;x++)
                    {
                        for(y=0;y<M;y++)
                        {
                            cbc[n1][x]= (cbc[n1][x]+ (cbc[n2][(x-y+M)%M]*subset_sum[y]))%mod;
                        }
                    }
                    memset(cbc[n2],0,sizeof(cbc[0]));
               }
               printf("%lld\n",cbc[n1][0]);
           }// query loop
       }
return 0;
}
