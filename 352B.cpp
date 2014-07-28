#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define VI vector<int>
#define mp make_pair
using namespace std;

vector<VI>jef(100006);
main()
{


    int N,i,flag,j,cd;
   scanf("%d",&N);
    int x;
    int maxm=-1;
    pair<int,int>pair_mp[100004];
    for(i=1;i<=N;i++)
    {
        scanf("%d",&x);
        jef[x].pb(i);
        maxm= max(x,maxm);

    }

    for(i=0;i<maxm+2;i++)
        jef[i].pb(i);


   int k=0;
    for(i=0;i<jef.size();i++)
    {
        if(jef[i].size()==2)
        {

             pair_mp[k]= mp( jef[i][ jef[i].size()-1], 0);

             k++;
        }
        else
        if(jef[i].size()>2)
        {
            flag=1;
                cd= jef[i][1]-jef[i][0];
                for(j=2;j<jef[i].size()-1;j++)
                {
                    if(jef[i][j]-jef[i][j-1] != cd)
                    {
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    pair_mp[k]= mp( jef[i][ jef[i].size()-1], cd);
                   k++;

                }
        }
    }
    sort(pair_mp,pair_mp+k);

    printf("%d\n",k);
    for(i=0;i<k;i++)
    {
        printf("%d %d\n",pair_mp[i].first,pair_mp[i].second);
    }


return 0;
}
