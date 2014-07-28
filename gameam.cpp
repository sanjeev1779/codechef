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
int euclid(int a,int x)//x>=a
{
    if(x==a)return 0; // losing postion for first
    if(x>=2*a)return 1;
    return (1-euclid(x%a,a));
}
main()
{
         //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int t;S(t);
        int N,x,y,ans,f,s,r;
        while(t--)
        {
            S(N);
            ans=0,f=0,s=0;
            while(N--)
            {
                cin>>x>>y;
                if(x>y)
                    swap(x,y);
                r= euclid(x,y);
//                if(r==1)
//                {
//                    printf("FIRST\n"); f++;
//                }
//                else {printf("SECOND\n"); s++;}
                ans=ans^r;
            }
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";

        }
return 0;
}
