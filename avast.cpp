//program SUBARR

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(long long x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[20];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int sum[1000002];

int getsum(int x)
{
  int ans=0;
  while(x)
    {
      ans+=sum[x];
      x^=x&-x;
    }
  return ans;
}

void add(int x,int n)
{
  while(x<=n)
    {
      sum[x]++;
      x+=x&-x;
    }
}

int main()
{
  int n=get(),k=get();
  static long long a[1000001],data[1000001];
  for(int i=a[0]=0;i<n;i++)
    a[i+1]=a[i]+get()-k;
  for(int i=0;i<=n;i++)
    data[i]=a[i];
  sort(data,data+n+1);
  for(int i=0;i<=n;i++)
    a[i]=lower_bound(data,data+n+1,a[i])-data;
  long long ans=0;
  for(int i=0;i<=n;i++)
    {
      ans+=getsum(a[i]+1);
      add(a[i]+1,n+1);
    }
  output(ans);
  return 0;
}
