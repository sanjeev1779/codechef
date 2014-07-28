#include<stdio.h>
main()
{
    int n,j,k,test_cases,i;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&n);
        int a[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<=n-2;j++)
            {
                if(a[i+1][j]>a[i][j+1])
                    a[i][j]+=a[i+1][j];
                else
                    a[i][j]+=a[i][j+1];
            }
        }
            printf("%d\n",a[0][0]);

    }
return 0;
}
