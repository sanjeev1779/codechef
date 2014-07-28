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

    double A_i, sum_b;
    while(test_cases--)
    {
        ans=0;
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

               if(n==2)
                {

                           if(abs(H[0]-D[0])==abs( D[1]-H[1]))
                                ans=abs(H[0]-D[0]);
                           else
                                ans=-1;
                }
                else
                {
                    sum_b= sum_D- sum_H; // (n-2)
                    for(i=0;i<n;i++)
                    {
                        A_i= (double) ( (sum_b - (n-2)*(D[i]-H[i]) )*1.0 ) /( (double) 2*(n-2)*1.0);
                        if( A_i<0 || (ceil(A_i) - floor(A_i)!=0) )
                        {
                            ans=-1;
                            break;
                        }
                        else
                            ans+=A_i;

                    }
                }
                cout<<ans<<endl;

    }


return 0;
}
