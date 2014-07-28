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
    int t,n,i,z,top,j;
    S(t);
    string str;
    while(t--)
    {
        cin>>n;
        cin>>str;
       int a[10]={0};
       int removed[10]={0};
        int l = str.size();
        for(i=0;i<l;i++)
        {
            z= (str[i]-'0');
            cout<<z<<endl;
            for(j=z;j>=1;j--)
            {
                if(removed[j]==0)
                {
                    a[j]=1; // push j
                }
                top=z;
            }
            int flag=0;
            for(j=z+1;j<=9;j++)
            {
                if(a[j]!=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                removed[top]=1;
            else
            {
                printf("No\n");
                return 0;
            }

        }
        printf("Yes\n");
    }

return 0;
}
