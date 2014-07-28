#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<bitset>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    LL sum=0;
    int x=0,ci,N,i;
    int minm=1000001;
    while(test_cases--)
    {
        cin>>N;
        minm=1000001;
        x=0;
        sum=0;
        for(i=0;i<N;i++)
        {
            cin>>ci;
            x=x^ci;
            sum+=ci;
            minm=min(ci,minm);
        }
        if(x==0)
            cout<<(sum-minm)<<endl;
        else
            cout<<"NO\n";

    }

return 0;
}
