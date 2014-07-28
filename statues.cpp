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
#define mp make_pair
using namespace std;
main()
{
    int N,sum,ans,i,avg;
   for(int j=1;;j++)
    {
        cin>>N;
        int a[53];
        sum=0;ans=0;
        if(N==0)
            break;
        else
        {
            for(i=0;i<N;i++)
            {
                S(a[i]);
                sum+=a[i];
            }
            avg= sum/N;
            for(i=0;i<N;i++)
            {
                if(a[i]>avg)
                    ans+=a[i]-avg;
            }
            printf("Set #%d\n",j);
            printf("The minimum number of moves is %d.\n",ans);
        }
    }

return 0;
}
