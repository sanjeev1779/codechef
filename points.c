#include<stdio.h>
main()
{
    int i,j,x,test_cases,temp,temp1,n,k,p;
    scanf("%d",&test_cases);

    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&n);
        int a[n][2];
        for(i=0;i<n;i++)
        {
            for(j=0;j<2;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        //sorting the above array as x

        for(i=0;i<n-1;i++)
        {
            x=a[i][1];
            for(j=i+1;j<n;j++)
            {
                if(a[j][0]<a[i][0])
                {
                    temp=a[j][0];
                    a[j][0]=a[i][0];
                    a[i][0]=temp;
                    temp1=a[j][1];
                    a[j][1]=a[i][1];
                    a[i][1]=temp1;

                }
            }
        }
        for(i=0;i<in-1;i++)
        {
            if(a[i][0]==a[i+1][0])
            {

            }
        }


        for(i=0;i<n;i++)
        {
            for(j=0;j<2;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }

        printf("sssss\n");

        for(i=0;i<n-1;i++)
        {
            if(a[i+1]==a[i])
            {
                dis= pow((a[i+1][0]-a[i][0]),2)+ pow((a[i+1][1]-a[i][1]),2)
            }

        }
    }

 return 0;
}
