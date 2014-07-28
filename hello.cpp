#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
main()
{
    int test_cases,i,ans;
    double D,R,min_cost,post_cost,org_cost;
    int U,N,M,C;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        cin>>D>>U>>N;
        min_cost= D*U;
        int p=1;
        for(i=1;i<=N;i++)
        {
            cin>>M>>R>>C;
            post_cost= R*U+ (double)C/ (double)M;
            if(post_cost<min_cost)
            {
                ans= i;
                p=0;
                min_cost= post_cost;
            }

        }
        if(p==1)
            cout<<0<<endl;
        else
            cout<<ans<<endl;
    }


return 0;
}
