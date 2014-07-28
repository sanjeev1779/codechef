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
main()
{
    int test_cases,i,N;
    S(test_cases);
    LL ans,x;
    LL xxor,bit;
    int cnt[35][2];
    while(test_cases--)
    {
        S(N);
        LL sum=0;
        xxor=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<32;i++)
            cnt[i][0]=1;
        for(int j=0;j<N;j++)
        {
           scanf("%lld",&x);
           xxor= xxor^x;
           for(i=0;i<32;i++)
           {
               bit=1<<i;
               if(xxor&(1<<i))
                 sum+= bit*cnt[i][0];
               else
                 sum+= bit*cnt[i][1];
           }
           for(i=0;i<32;i++)
           {
               bit=1<<i;
               if(xxor&(1<<i))
                 cnt[i][1]++;
               else
                 cnt[i][0]++;
           }
        }
        cout<<sum<<endl;

    }

return 0;
}
