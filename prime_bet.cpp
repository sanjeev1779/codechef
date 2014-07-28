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

int S[1000002];
void sieve(LL m,LL n)
{
 LL x=sqrt(n);
LL i,j;
LL a;

 for(i=0;i<=n-m+2;i++)
 S[i]=0;

 if(m%2==0)
     i=m;

 else {
   i=m+1;

      }

 for (;i<=n;i+=2){
       S[i-m]=1;

            }


 for (i=3;i<=x;i+=2){

     if(i>=m && S[i-m]) continue;

    if(i*i>=m)j=i*i;
     else {
     a = (m-i*i)%(2*i);
      if(a==0)j=m;
       else
      j=m+ (2*i -a);
    }
     for (;j<=n;j+=2*i){

            S[j-m]=1;
              }
   }
 if (m==1)i=1; else i=0;
 for (;i<=n-m;i++)

     if (!S[i]){
       printf("%lld\n",i+m);
       }
}

main(){
  int t;
  LL m,n;
  scanf("%d",&t);
  while(t--){
      scanf("%lld %lld",&m,&n);
      if(m<=2)
        {
            printf("2\n");
            m++;
        }
      sieve(m,n);
      printf("\n");
         }
return 0;
}
