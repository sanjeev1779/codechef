#include<stdio.h>
/*#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define vector<int>VI
using namespace std;*/
main()
{
    int t,i,p,dig,num,j,rem;
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37};
    scanf("%d",&t);
    int l,u;
    while(t--)
    {
        scanf("%d",&l);scanf("%d",&u);
         p=0;
        for(i=l;i<=u;i++)
        {
            num=i;
            dig=0;
            while(num>0)
            {
                rem= num%10;
                num=num/10;
                dig+=rem;
            }


            for(j= 0;j<12;j++)
            {
                if(prime[j]==dig)
                {
                    p++;
                    break;
                }
            }

        }
         printf("%d\n",p);
    }


return 0;
}
