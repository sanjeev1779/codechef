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
    int R,C,i,j,row_index,k;
    LL a[102][102];
    S(R);
    S(C);
    int flag=0;
    int col_index;
    LL minm,maxm;
    vector<long long int>vec_cost;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
            scanf("%lld",&a[i][j]);
    }
    int x;
    for(i=0;i<R;i++)
    {
        minm=a[i][0];
        col_index=0;
        for(j=1;j<C;j++)
        {
            if(a[i][j]<=minm)
            {
                minm=a[i][j];
                col_index=j;
            }
        }
        for(x=0;x<C;x++)
        {
            if(a[i][x]==minm)
            {
                col_index=x;
              //  cout<<"minm:" <<minm<<endl;
                 maxm=a[0][col_index];
                 row_index=0;

                for(k=1;k<R;k++)
                {
                    if(a[k][col_index]>=maxm)
                    {
                        maxm=a[k][col_index];
                        row_index=k;
                    }
                }
               // cout<<"maxm:"<<maxm<<endl;
                //cout<<"next\n";
                if(maxm==minm)
                {
                    flag=1;
                  //  cout<<maxm;
                    vec_cost.pb(maxm);
                }
            }


            }
    }
    if(flag==1){
    int l= vec_cost.size();
    cout<<vec_cost[0]<<endl;
    }
    else
        cout<<"GUESS\n";


return 0;
}
