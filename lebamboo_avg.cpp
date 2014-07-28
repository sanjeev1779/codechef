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

    int test_cases, sum_H, sum_D,i,n,rem,diff,ans;
    S(test_cases);
    int H[52];
    int D[52];
    while(test_cases--)
    {
        S(n);
        sum_H=0;
        sum_D=0;
        for(i=0;i<n;i++)
        {
            S(H[i]);
            sum_H+= H[i];
        }
        for(i=0;i<n;i++)
        {
            S(D[i]);
            sum_D+= D[i];
        }

        if(n==1)
        {
            if(sum_H>= sum_D)
                ans=sum_H-sum_D;
            else
                ans= -1;
        }
        else if(n==2)
        {

                   if(abs(H[0]-D[0])==abs( D[1]-H[1]))
                        ans=abs(H[0]-D[0]);
                   else
                        ans=-1;
        }

        else
        {
            int flag;
            if(sum_D== sum_H)
            {
                flag=1;
                for(i=0;i<n;i++)
                {
                    if(H[i]!=D[i])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    ans=-1;
                else ans=0;

            }
            else
            {
                diff= sum_D- sum_H;

                if( diff%(n-2)==0)
                    ans= diff/(n-2);
                else
                    ans=-1;
            }
        }
        printf("%d\n",ans);
    }

return 0;
}
