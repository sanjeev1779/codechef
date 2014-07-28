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
    int test_cases,n,m,k,temp;
    S(test_cases);
    string st;
    int ans;
    while(test_cases--)
    {
        ans=0;
        S(n);
        S(m);
        S(k);
        int sum[51][51];
        int i,j,maxm,row;
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++)
        {
            cin>>st;
            for(j=0;j<m;j++)
            {
                if(st[j]=='.')
                {
                        sum[i][0]++;
                }
                else
                {
                        sum[i][1]++;
                }
            }
        }
    /*    for(i=0;i<n;i++)
            for(j=0;j<m;j++)
             printf("%d ",a[i][j]);
        cout<<"hi \n";
        for(i=0;i<n;i++)
        {
            cout<<sum[i][0]<<" "<<sum[i][1]<<endl;
        }*/
        while(k--)
        {
            maxm=0;
            for(i=0;i<n;i++)
            {
                if(sum[i][0]>=maxm)
                   {
                       maxm=sum[i][0]; // the row having maxm off
                       row=i;
                   }
            }
           // cout<<"row= "<<row<<endl;
            temp=sum[row][0];
            sum[row][0]=sum[row][1];
            sum[row][1]=temp;

        }
        for(i=0;i<n;i++)
            ans+=sum[i][1];
        cout<<ans<<endl;
    }

return 0;
}
