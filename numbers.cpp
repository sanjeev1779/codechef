#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
#define traverse_map(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
main()
{
    int test_cases,n,i;
    S(test_cases);
    LL fst,un;
    LL ans_val;

    while(test_cases--)
    {

        ans_val=-1;
        S(n);
        string str[n+2];
        map<LL,int>freq;
        pair<string,LL>par[n+2];
        for(i=0;i<n;i++)
        {
            cin>>str[i]>>un;
            freq[un]++;
            par[i]=mp(str[i],un);
        }
        //cout<<"hi\n";
        traverse_map(freq,it)
        {
            fst=(*it).first;
            if( (*it).second==1)
            {
                ans_val= fst;
                break;
            }
        }
        if(ans_val==-1)
        {
            printf("Nobody wins.\n");
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(par[i].second==ans_val)
                {
                   // printf("%s\n",par[i].first);
                   cout<<par[i].first<<endl;
                    break;
                }
            }
        }
    }

return 0;
}
