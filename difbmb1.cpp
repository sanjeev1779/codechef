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
    int test_cases;
    S(test_cases);
    LL a,b,i,j;
    int p;
    LL ans,x;
    while(test_cases--)
    {
        cin>>a>>b;
        ans=0;
        if(a==1)
            a++;
        for(i=a;i<=b;i++)
        {
                p=0;
                x=i;
                for(j=2;j*j<=x;j++)
                {
                    if(x%j==0)
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0)
                {
                    if( (i-3)%4!=0)
                        ans++;
                }
        }
        cout<<ans<<endl;
    }

return 0;
}
