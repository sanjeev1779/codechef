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
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
       int k,i,j;
       string str;
       cin>>k;
        int freq[11]={0};
       for(i=1;i<=4;i++)
       {
           cin>>str;
           for(j=0;j<4;j++)
           {
               if(str[j]!='.')
                  freq[str[j]-'0']++;
           }
       }
        int flag=0;
       for(i=1;i<=9;i++)
       {
           if(freq[i]>2*k)
           {
               flag=1;
               break;
           }
       }
       if(flag)
         cout<<"NO\n";
       else
        cout<<"YES\n";


return 0;
}
