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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    LL fact[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000};
    int test_cases,i,j,l,cnt,x,y;
    S(test_cases);
    string str;
    LL ans;
    while(test_cases--)
    {
        cin>>str;
        ans=0;
        for(i=0;i<l;i++)
        {
            y=1;
            cnt=0;
            int a[10]={0};
            x= str[i]-'0';
            for(j=i+1;j<l;j++)
            {
                if(x>(str[j]-'0') )
                    cnt++;
            }
            for(j=i+1;j<l;j++)
            {
                x=str[j]-'0';
                a[x]++;
            }
            for(x=0;x<10;x++)
                y*=fact[a[x]];
            ans+= cnt*(l-i-1)/y;

        }
        cout<<ans+1<<endl;
    }
return 0;
}
