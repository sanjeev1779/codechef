#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL unsigned long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL gcd(LL a, LL b){ LL temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      LL power[65];
      power[0]=1;
      for(int i=1;i<=63;i++)
      {
          power[i]=power[i-1]*2;
      }
        int t;
        S(t);
        while(t--)
        {
            LL p,q,t1,t2,t3;
            int ch=0;
            cin>>p>>q;
            for(int r=1;r<=34;r++)
            {
                t1= q*power[r];
                t2= p*(power[r]-1);
         //     cout<<t1<<"\t"<<t2<<endl;
                if(t1%t2==0)
                {
                    t3= t1/t2;
                    for(int i=0;i<=34;i++)
                    {
                        if(t3==power[i])
                        {
                            ch=1; break;
                        }
                    }
                    if(ch==1)break;
                }
            }
            if(ch)
                printf("YES\n");
            else printf("NO\n");
        }
return 0;
}
