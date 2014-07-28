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
    pair<int,int>p[100];
    int N,i,x,y;
    S(N);
    for(i=0;i<N;i++)
    {
        S(x);
        S(y);
        p[i]= mp(x,y);
    }

    for(i=0;i<N;i++)
    {
        printf("%d %d\n",p[i].first, p[i].second);
    }
    sort(p,p+N);
    cout<<"after sorting\n";
    for(i=0;i<N;i++)
    {
        printf("%d %d\n",p[i].first, p[i].second);
    }
    cout<<"after deletion";
    cin>>x;
    for(i=0;i<N;i++)
    {
        if(p[i].first==x)
            p[i].first=10;
    }
    for(i=0;i<N;i++)
    {
        printf("%d %d\n",p[i].first, p[i].second);
    }


return 0;
}
