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
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int a,t,b,c,cnt,maxm,ans,sum;
    S(t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        cnt=0;
        maxm=-1;
        while(cnt<=10000)
        {
            if(b>=c)
            {
                b=b-c;

            }
            else
            {
                if(a>0)
                {
                    a--;
                    b=100+b-c;
                }
                else break;
            }
            sum= a*100+b;
            if(sum>maxm)
            {
                maxm=sum; ans=cnt;
            }
            swap(a,b); cnt++;

            //cout<<a<<b<<endl;
        }
        cout<<ans<<endl;
    }
return 0;
}
