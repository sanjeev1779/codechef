#include<iostream>
#include<algorithm>
#include<stdio.h>
bool comp(int a,int b)
{
     return a>b;
}

using namespace std;

int main()
{
    char buf[10];
    int t,i,n,tc=1;
    int a[10],b[10],sum;
    scanf("%s",buf);
    //cout<<buf;
    scanf("%d",&t);
    //cout<<t;
    while(scanf("%d",&n)!=EOF)
    {
              sum=0;
              //scanf("%d",&n);
              for(i=0;i<n;i++)
              {
                  scanf("%d",&a[i]);
              }

              for(i=0;i<n;i++)
              {
                  scanf("%d",&b[i]);
              }

              sort(a,a+n);
              sort(b,b+n);
              for(i=0;i<n;i++)
              {
                  sum+=(a[i]*b[i]);
              }
              printf("Case #%d: %d\n",tc++,sum);
    }
    return 0;
}
