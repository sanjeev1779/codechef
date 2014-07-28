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
using namespace std;
main()
{
    int test,i,j;
    S(test);
    LL ans;
    LL K;
    LL N;
    LL Arr[1002];
    string str;
    while(test--)
    {
        scanf("%lld",&N);
        memset(Arr,0,sizeof(Arr));
        scanf("%lld %lld",&K,&ans);

        for(i=0;i<N;i++)
        {
            scanf("%lld",&Arr[i]);
        }
        LL ans1= ans;
        cin>>str;
        if(str=="XOR")
        {
            if(K%2==0)
                ans1=ans;

            else
            {
                ans1=0;
                for(j=0;j<N;j++)
                {
                    ans1= (ans1)^(Arr[j]);
                }
                ans1=ans^ans1;
            }
            cout<<ans1<<endl;
        }
       else if(str=="OR")
        {
            if(K==0)
                ans1=ans;
            else
            {
                for(j=0;j<N;j++)
                {
                    ans1= ans1 | Arr[j];
                }
            }
            cout<<ans1<<endl;
        }
        else if(str=="AND")
        {
             if(K==0)
                ans1=ans;
            else
            {
                for(j=0;j<N;j++)
                {
                    ans1= ans1 &  Arr[j];
                }
            }
            cout<<ans1<<endl;
        }
    }

return 0;
}
