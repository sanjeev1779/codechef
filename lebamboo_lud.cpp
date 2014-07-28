#include<iostream>
#include<stdio.h>
#include<cmath>
#define LL long long
using namespace std;
int main()
{
    int n,i,k,j,p;
    int t;
    scanf("%d",&t);
    LL ans;
     while(t--)
    {
        ans=0;
        double H[55],D[55];
            double a[55][55],l[55][55]={0},u[55][55]={0},sum,b[55],z[55]={0},x[55]={0};


            cin>>n;
            for(i=1;i<=n;i++)
            {
                cin>>H[i];
            }
            for(i=1;i<=n;i++)
            {
                cin>>D[i];
            }

            if(n==1)
        {
            if(H[1]>= D[1])
                ans=H[1]-D[1];
            else
                ans= -1;
        }
        else if(n==2)
        {

                   if(abs(H[2]-D[2])==abs( D[1]-H[1]))
                        ans=abs(H[1]-D[1]);
                   else
                        ans=-1;
        }
        else
        {
                    for(i=1;i<=n;i++)
                    {
                        for(j=1;j<=n;j++)
                        {
                            if(j==n-i+1)
                                a[i][j]=-1;
                            else
                                a[i][j]=1;
                        }
                    }


                    for(i=1;i<=n;i++)
                        b[i]=D[i]-H[i];

                    for(k=1;k<=n;k++)
                    {
                        u[k][k]=1;
                        for(i=k;i<=n;i++)
                        {
                            sum=0;
                            for(p=1;p<=k-1;p++)
                                sum+=l[i][p]*u[p][k];
                            l[i][k]=a[i][k]-sum;
                        }

                        for(j=k+1;j<=n;j++)
                        {
                            sum=0;
                            for(p=1;p<=k-1;p++)
                                sum+=l[k][p]*u[p][j];
                            u[k][j]=(a[k][j]-sum)/l[k][k];
                        }
                    }


                    for(i=1;i<=n;i++)
                    {                                        //forward subtitution method
                        sum=0;
                        for(p=1;p<i;p++)
                        sum+=l[i][p]*z[p];
                        z[i]=(b[i]-sum)/l[i][i];
                    }


                    for(i=n;i>0;i--)
                    {
                        sum=0;
                        for(p=n;p>i;p--)
                            sum+=u[i][p]*x[p];
                        x[i]=(z[i]-sum)/u[i][i];
                    }

                    for(i=1;i<=n;i++)
                       {
                          cout<<endl<<x[i];
                          if(x[i]<0 || ceil(x[i])-floor(x[i])!=0 )
                            {
                                ans=-1;
                                break;
                            }

                           ans+= x[i];
                       }
        }
               cout<<ans<<endl;
    }
    return 0;
}
