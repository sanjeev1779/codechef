#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stdio.h>
typedef unsigned long long ULL;
using namespace std;

int minm(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}


int  gcd(ULL a,int b)
{
	int c;
	while(b>0) c=a%b, a=b, b=c;
	return a;
}

int solve(int n,int k)
{
    int c=1,g,i;
    if(k>n)
        return 0;
    if(k>n-k)
      k=n-k;
   for(i=1;i<=k;i++)
   {
        g=gcd(c,i);
        c=c/g;
        c*= (n-i+1)/(i/g);
   }
   return c;
}


main()
{
    int test_cases,S,N,M,K,i,ran;
    float ans,each;

    cin>>test_cases;
    while(test_cases--)
    {
        cin>>S>>N>>M>>K;

        if(N<K+1)
        {
            printf("0.000000\n");
        }
        else if(N==S)
            printf("1.000000\n");

        else
        {
            ans=0;
            int ran=minm(N,M);
            for(i=K;i<ran;i++)
            {
                each= (float) (solve(S-M,N-1-i)* solve(M-1,i) )/ (solve(S-1,N-1));
                printf("each=%f\n",each);
                ans+=each;
            }
            printf("%.6f\n",ans);
        }
    }

return 0;
}
