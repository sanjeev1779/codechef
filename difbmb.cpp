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
int is_prime(LL a)
{
    LL j;
    int p=0;
    for(j=2;j*j<=a;j++)
    {
        if(a%j==0)
        {
            p=1;
            break;
        }
    }
    if(p==1)
        return 0;
    else
        return 1;
}
main()
{
    int test_cases;
    S(test_cases);
    LL a,b,i,ans;
    int x;
    while(test_cases--)
    {
        ans=0;
        //scanf("%lld %lld",&a,&b);
        cin>>a>>b;
        for(i=a;i<=b;i++)
        {
            x= is_prime(i);
            printf("%d is %d\n",i,x);
            if(x==1)
            {
                if( (i-3)%4!=0)
                    ans++;
            }
        }
        printf("%lld\n",ans);

    }

return 0;
}
