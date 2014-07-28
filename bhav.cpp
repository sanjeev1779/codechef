#include<iostream>
#include<stdio.h>
#define LL long long
using namespace std;
main()
{
    LL t,S,C,N,cost,rem;
    cin>>t;
    while(t--)
    {
        cin>>N>>S>>C;
        rem= S-N;
        if(rem<=0)
            cost=0;
        else
        cost= (rem+1)/2;

        if(cost<=C)
        {
            printf("YES %lld\n",cost);
        }
        else
            cout<<"NO";
    }
return 0;
}
