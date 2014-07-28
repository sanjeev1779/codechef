#include<stdio.h>
#include<math.h>
int ch(long long int);
main()
{
long long int a[125];
long long int u,v,i,j,k;
j=0;
for(i=0;i<125;i++)
a[i]=0;
for(i=0;i<100000;i++)
 {
  k=i*i;
  if(ch(k)==1)
  {
  a[j]=k;
  j=j+1;
  }
 }
long long int t,s,v1,v2;
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%lld %lld",&u,&v);
s=0;
for(j=0;j<125;j++)
{
if(a[j]>v)
break;
if(a[j]>=u)
s=s+1;
}
printf("%lld\n",s);
}
return 0;
}
int ch(long long int n)
{
long long int c,d;
int x=1;
c=n;
d=1;
while(c!=0)
{
d=c%10;
c=c/10;
if((d==2)||(d==3)||(d==5)||(d==6)||(d==7)||(d==8))
{x=0;
break;
}
}
return x;
}
