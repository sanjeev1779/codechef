#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N)
#define S(N) scanf("%d",&N)
#define SL(N) scanf("%lld",&N)
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    int N,i,x,y;
    LL a,b,ans,maxm;
    int j;
    while(test_cases--)
    {
        S(N);
        LL M[N+1];
        int p_non_overlap[N+1];
        memset(M,0,sizeof(M));
        pair<LL,LL>p_sort[N+1];
        //cout<<N<<endl;
        for(i=0;i<N;i++)
        {
           scanf("%lld %lld",&x,&y);
           // p_org[i]=mp(s,f);
            p_sort[i]=mp(y,x);
            cout<<"hi\n";
        }
        sort(p_sort,p_sort+N);
        p_non_overlap[0]=0;
       // last_finish=p_sort[0].first;
        for(i=1;i<N;i++)
        {
            /*if(last_finish < p_sort[i].second)
            {
                p_non_overlap[i]=p_non_overlap[i-1]+1;
                last_finish=p_sort[i].first; // last finish
            }
            else
                p_non_overlap[i]=p_non_overlap[i-1];*/
                int cnt=0;
                for(j=i-1;j>=0;j--)
                {
                    if(p_sort[j].first<p_sort[i].second)
                        {
                            cnt=j;
                            break;
                        }
                }
                p_non_overlap[i]=cnt;
        }
        M[0]= p_sort[0].first- p_sort[0].second+1;
        for(j=1;j<N;j++)
        {
            M[j]= max( M[j-1],  (  (p_sort[j].first- p_sort[j].second)+1+ M[j-1]));
        }
        printf("%lld\n",M[N-1]);
    }
return 0;
}
