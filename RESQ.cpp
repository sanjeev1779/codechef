#include<stdio.h>
#include<math.h>
main()
{
	int t,n,i,ans,min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		min=n-1;
		for(i=2;i<=n/4+1;i++)
		{
			if(n%i==0) //I IS WIDTH
			{
				ans=abs(n/i-i);
				if(ans<=min)
				{
					min=ans;
				}
			}
		}
		printf("%d\n",min);
	}

return 0;
}
