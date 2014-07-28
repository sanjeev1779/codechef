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
LL inverse_j[100005];
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}

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
void precompute()
{
    for(int i=0;i<maxm;i++)
    {
         inverse_j[i]= fast_exp_pow(i,1000000005,1000000007);
    }
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       precompute();
       int x,y,test_cases,N,Q,i,j,k,n1,n2,M;
       LL mod=1000000007;
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
               S(M);
                memset(cbc,0,sizeof(cbc));
                memset(freq,0,sizeof(freq));
               // calculate the frequency of each number modulo M
               for(i=0;i<N;i++)
               {
                   x= (cards[i]%M+M)%M; // cards can have -ve numbers
                   freq[x]++; // x <M
               }
              // for(i=0;i<M;i++) cout<<freq[i]<<" ";
               //cout<<endl;
               // find the number of different subsets which generate from 0 to m

               n1=0;
               n2=1;
               for(i=0;i<M;i++)// from 0 to <M
               {
                   times=1;
                   swap(n1,n2);
                   memset(subset_sum,0,sizeof(subset_sum));
                   for(j=0;j<=freq[i];j++)
                   {
                       x=(i*j)%M; // using number i-> j times
                       subset_sum[x]= (subset_sum[x]+times)%mod;
                       times= ( (((freq[i]-j)*times)%mod)*(inverse_j[j+1]))%mod;
                   }

                    //

                    for(x=0;x<M;x++)
                    {
                        for(y=0;y<M;y++)
                        {
                            cbc[n1][x]= (cbc[n1][x]+ (cbc[n2][(x-y+M)%M]*subset_sum[y])%mod)%mod;
                        }
                    }
                    memset(cbc[n2],0,sizeof(cbc[0]));
               }
               printf("%lld\n",cbc[n1][0]);
           }// query loop
       }
return 0;
}
