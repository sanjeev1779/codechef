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
    int t;
    S(t);
    int num;
    int x=0;
    int ci;
    LL sum=0;
    int minm=1000001;
    while(t--)
    {
        cin>>N;
        sum=0;
        while(N--)
        {
            cin>>ci;
            x=x^ci;
            minm= min(ci,minm);
            sum+=ci;
        }
        if(x==0)
            cout<<(sum-minm)<<endl;
    }

return 0;
}
