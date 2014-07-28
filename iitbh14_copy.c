#include<stdio.h>
main()
{
    int t,c,n,i,j,x;
    int a[105];
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
       scanf("%d %d",&c,&n);
        int flag=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]+a[j]==c)
                {
                   printf("Case #%d: %d %d\n",x,i+1,j+1);
                    flag=0;
                }
            }
            if(!flag)
                break;
        }
    }

return 0;
}
