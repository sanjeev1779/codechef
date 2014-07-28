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
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      string str;
       cin>>str;
       int l=0,r=0,x,i;

       int le= str.length();
       int flag=0;
       for(i=0;i<le;i++)
       {
           if(str[i]=='^')
            {
                flag=1;

            continue;
            }
            if(flag==0 && str[i]!='=')
            {
                x=(str[i]-'0');
                    l+=x;
            }
           if(flag==1 && str[i]!='=')
            {
                x=(str[i]-'0');
                    r+=x;
            }
       }
      // cout<<l<<" "<<r<<endl;
       if(l==r)
        cout<<"balance\n";
       if(l<r)
        cout<<"right\n";
       else cout<<"left\n";


return 0;
}
