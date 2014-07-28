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
    int test_cases,i,N,j,key,num_of_ones;
    S(test_cases);
    LL x;
    vector<LL>A,B;
    double ans;
    LL maxm;
    LL num;
    while(test_cases--)
    {
        B.clear();
        A.clear();
        S(N);
        num=0;
        maxm= -1;
        for(i=0;i<N;i++)
        {
                    scanf("%lld",&x);
                    A.pb(x);
        }
        for(i=0;i<N;i++)
            {
                scanf("%lld",&x);
                B.pb(x);
                maxm= max(maxm,x);
            }
        sort(B.begin(),B.end());
        num_of_ones= upper_bound( B.begin(), B.end(),1)- lower_bound(B.begin(), B.end(),1);
        for(i=0;i<N;i++)
        {
            if(A[i]==2)
            {
                key= upper_bound( B.begin(), B.end(),maxm+4)- lower_bound(B.begin(), B.end(),5);
                num= num+ key + num_of_ones;
            }
            if(A[i]==3)
            {
                key= upper_bound( B.begin(), B.end(),2)- lower_bound(B.begin(), B.end(),2);
                num+= key;
            }
            if(A[i]>=3)
            {
                key= upper_bound( B.begin(), B.end(),maxm+4)- lower_bound(B.begin(), B.end(),A[i]+1);
                num+= key+num_of_ones;
            }
        }
        ans= (double)(num*1.0)/(N*1.0);
        printf("%.6lf\n",ans);
    }
return 0;
}
