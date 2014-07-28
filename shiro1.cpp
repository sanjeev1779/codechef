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
int N;
int a[101];
double prob[101];
double dp(int pos,int cur_sum)
{


}
main()
{
    int test_cases;
    S(test_cases);
    while(test_cases--)
    {
        S(N);
        for(i=0;i<N;i++)
            cin>>a[i];
        for(i=0;i<N;i++)
            cin>>prob[i];
        cout<<dp(0,0)<<endl;


    }

return 0;
}
