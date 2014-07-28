#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) prLLf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
   LL fast_pow(LL a, LL b)
{
    LL prod= 1;
    while(b>0)
    {
        if(b%2)
            prod= (prod*a);
        a= (a*a);
        b=b/2;
    }
    return prod;
}

main()
{
    int test_cases,i,j,l;
    LL ans=0;
    S(test_cases);
    char ch[62];
    int times[125];
    LL cnt;
    int a[125];
    while(test_cases--)
    {
        ans=0;
        scanf("%s",ch);
        l = strlen(ch);
        cnt=0;
        memset(times,0,sizeof(times));
        memset(a,-1,sizeof(a));
        for(i=0;i<l;i++)
        {
            times[ch[i]]++;
        }
        for(i=45;i<125;i++)
        {
            if(times[i])
                cnt++;
        }
        if(cnt==1)
            cnt++;
        a[ch[0]]=1;
        j=0;
        for(i=1;i<l;i++)
        {
            if(a[ch[i]]==-1)
            {
                a[ch[i]]=j;
                j++;
                if(j==1)
                    j++;
            }
        }
        for(i=l-1;i>=0;i--)
        {
            ans+=  a[ch[i]]*fast_pow(cnt,l-1-i);
            //power*=cnt;
        }
        printf("%lld\n",ans);
    }


return 0;
}
