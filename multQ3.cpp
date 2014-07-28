#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

int BIT[100003];
int N,Q;
void update(int val,int idx)
{
    while(idx<=N)
    {
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}

int get_sum(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
main()
{
        freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
        S(N);S(Q);
        int TAG,A,B;
        while(Q--)
        {
            S(TAG);S(A);S(B);
            A++;B++;
            if(!TAG)
            {
                update(1,A);
                update(-1,B+1);
            }
            else
            {
                int left=get_sum(A-1);
                int right=get_sum(B);
                int sum=right-left;
                cout<<sum<<endl;
            }
        }
return 0;
}
