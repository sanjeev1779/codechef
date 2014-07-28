#include<stdio.h>
#include<string.h>
main()
{
int t,i,j,k,l,s;
scanf("%d",&t);

int m[300],n[300];  //m is for jwel and n is for mined
for(i=0;i<300;i++)
{
n[i]=0;
m[i]=0;
}
for(i=0;i<t;i++)
{
    char *a,*b;
a=(char*)malloc(sizeof(char)*105);
b=(char*)malloc(sizeof(char)*105);
scanf("%s %s",a,b);
	l=strlen(a);
	for(j=0;j<l;j++)
	{
        k=(*(a+j));
        m[k]=1;
	}
	l=strlen(b);
	for(j=0;j<l;j++)
	{
	k=(*(b+j));
	n[k]=n[k]+1;
	}
s=0;
for(j=0;j<300;j++)
if((m[j]==1)&&(n[j]!=0))
s=s+n[j];
printf("%d\n",s);
free(a);
free(b);
	for(j=0;j<300;j++)
	{
	n[j]=0;
	m[j]=0;
	}


}
return 0;
}
