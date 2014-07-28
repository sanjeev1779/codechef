#include<stdio.h>
#include<string.h>
int main()
{
	int t,k;
	scanf("%d\n",&t);
	int a[105],b[105];
	for(k=0;k<t;k++)
	{
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
        int n1,n2,replace=0,i,j,p,q,ans=0;
        scanf("%d",&n1);
        for(i=0;i<n1;i++)
             scanf("%d",&a[i]);


         scanf("%d",&n2);
         for(j=0;j<n2;j++)
         {
              scanf("%d",&b[j]);
        }

         for(j=0;j<n2;j++)
             for(i=0;i<n1;i++)
              {
                  if(b[j]==a[i]) replace++;
              }
         if(n1==n2)
          ans= n2-replace;
         else if(n1>n2)
                ans= (n2-replace)+ n1-n2;
         else
             ans=n1-replace + n2-n1;
        printf("%d\n",ans);
	}
return 0;
}
