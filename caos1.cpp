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
    int test_cases,i,j,R,C;
    S(test_cases);
    string str;
    int a[52][52];
    while(test_cases--)
    {
        S(R);
        S(C);
        memset(a,0,sizeof(a));
        for(i=0;i<R;i++)
        {
            cin>>str;
            for(j=0;j<C;j++)
            {
                if(str[j]=='^')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        }
        int ans=0;
        for(i=2;i<R-2;i++)
        {
            for(j=2;j<C-2;j++)
            {
                    if(a[i][j]==1)
                    {
                         ans+= a[i][j+1] && a[i][j+2] && a[i-1][j] &&a[i-2][j] && a[i+1][j] &&a[i+2][j] && a[i][j-1] && a[i][j-2];


                    }

            }
        }
        cout<<ans<<endl;
    }

return 0;
}
