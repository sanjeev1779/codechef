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
#define VI vector<int>
using namespace std;
main()
{
    int n,idx,a,b,s,M,k,q,i,j;
    LL amount[100002];
    memset(amount,0,sizeof(amount));
    S(n);
    S(q);
    string ch;
    s=0;
    while(q--)
    {
        cin>>ch;

        if(ch=="UPDATE")
        {
          //  cout<<"hi"<<endl;
           scanf("%d %d",&i,&M);
           for(j=1;j*i<=n;j++)
           {
                amount[j*i]+=M;
           }
        }
        else
        {
            scanf("%d",&idx);
            printf("%lld\n",amount[idx]);

        }
    }
return 0;
}
