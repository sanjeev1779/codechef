// codeforces
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
#define SL(N) scanf("%d",&N);
#define pb push_back
using namespace std;
main()
{
     //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        LL n,m,x,y,z,p,temp;
        LL r;
        LL k1,k2,n1,m1;
        cin>>n>>m>>x>>y>>z>>p;
        while(p--)
        {
            n1=n;
            m1=m;
            cin>>k1>>k2;
            r= x%4;
            while(r--)
            {
                temp= k2;
                k2=n1-k1+1;
                k1=temp;

                temp=n1;
                n1=m1;
                m1=temp;
            }
            r=y%2;
            while(r--)
            {
                k2=m1-k2+1;
            }
            r= z%4;
            while(r--)
            {
                 temp= k1;
                k1=m1-k2+1;
                k2=temp;

                  temp=n1;
                n1=m1;
                m1=temp;
            }
            cout<<k1<<" "<<k2<<endl;
        }
return 0;
}
