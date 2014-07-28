#include<stdio.h>
//using namespace std;
main()
{
    int t,c,n,i,j,x;
    //cin>>t;
    scanf("%d",&t);
    x=1;
    while(t--)
    {
        scanf("%d %d",&c,&n);
        int a[n];
        int flag=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]+a[j]==c)
                {
                    printf("Case #%d: %d %d\n",x,i+1,j+1);
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        x++;
    }

return 0;
}
