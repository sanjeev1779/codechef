#include<iostream>
using namespace std;
int main()
{
    int t,n,p,temp;
    int i,j,k;
    int data[43][43][43];
    int ans1,ans2;
    string sa,sb;
    cin >> t;
    while(t--)
    {
        int a[43][43][43]={0};
        cin >> n >> p;
        cin >> sa >> sb;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(sa[i*n*n+j*n+k]==sb[i*n*n+j*n+k])
                        data[i+1][j+1][k+1]=1;
                    else
                        data[i+1][j+1][k+1]=0;
                }
            }
        }
        a[1][1][1]=data[1][1][1];
        for(j=2;j<=n;j++)
        {
            a[1][j][1]=a[1][j-1][1]+data[1][j][1];
        }
        for(k=2;k<=n;k++)
        {
            a[1][1][k]=a[1][1][k-1]+data[1][1][k];
        }
        for(i=2;i<=n;i++)
        {
            a[i][1][1]=a[i-1][1][1]+data[i][1][1];
        }
        for(j=2;j<=n;j++)
        {
            for(k=2;k<=n;k++)
            {
                a[1][j][k]=a[1][j-1][k]+a[1][j][k-1]-a[1][j-1][k-1]+data[1][j][k];
            }
        }
        for(j=2;j<=n;j++)
        {
            for(k=2;k<=n;k++)
            {
                a[j][1][k]=a[j-1][1][k]+a[j][1][k-1]-a[j-1][1][k-1]+data[j][1][k];
            }
        }
        for(j=2;j<=n;j++)
        {
            for(k=2;k<=n;k++)
            {
                a[j][k][1]=a[j-1][k][1]+a[j][k-1][1]-a[j-1][k-1][1]+data[j][k][1];
            }
        }
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=n;j++)
            {
                for(k=2;k<=n;k++)
                {
                    a[i][j][k]=a[i-1][j][k]+a[i][j-1][k]+a[i][j][k-1]+data[i][j][k]+a[i-1][j-1][k-1]-a[i-1][j-1][k]-a[i][j-1][k-1]-a[i-1][j][k-1];
                }
            }
        }
        int diff=n-1;
        int ch=0;
        ans1=-1;
        while(diff>=0)
        {
            ans2=0;
            for(i=1;i<=n-diff;i++)
            {
                for(j=1;j<=n-diff;j++)
                {
                    for(k=1;k<=n-diff;k++)
                    {
temp=a[i+diff][j+diff][k+diff]-a[i-1][j+diff][k+diff]-a[i+diff][j-1][k+diff]-a[i+diff][j+diff][k-1]+a[i-1][j-1][k+diff]+a[i-1][j+diff][k-1]+a[i+diff][j-1][k-1]-a[i-1][j-1][k-1];
                        if(temp*100>=p*(diff+1)*(diff+1)*(diff+1))
                        {
                            ch=1;
                            cout<<diff<<endl;
                            ans1=diff+1;
                            ans2++;
                        }
                    }
                }
            }
            if(ch==1)
            {
                cout << ans1 << " " << ans2 << "\n";
                break;
            }
            if(ch==0 && diff==0)
            {
                cout << "-1\n";
                break;
            }
            if(ch==0)
            {
                diff=diff-1;
            }
        }
    }
    return 0;
}
