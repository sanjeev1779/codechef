#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<climits>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
#define traverse_map(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
main()
{
    int n,fst,i,x,to_be_added;
    S(n);
    LL last=-1;
    int maxm=-1;
    LL ans=0;
    int distinct=0;
    map<int,int>freq;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        freq[x]++;
        maxm= max(x,maxm);
        while(freq[x]==2)
        {
            freq[x]=0; // make it zero
            x++;
            freq[x]++; // and increase the next element freq by one
            maxm= max(x,maxm);
        }
    }
     //for(it=freq.begin();it!=freq.end();it++)
     traverse_map(freq,it)
        {
            fst= (*it).first;
            if((*it).second==1)
            {
                //distinct++;
                //maxm=((*it).second);
                to_be_added= fst-last-1;
                ans+= to_be_added;
                last=fst;
            }
        }
     //   int ans= maxm-distinct+1;
       printf("%lld\n",ans);
return 0;
}
