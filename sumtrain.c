#include<stdio.h>
int fastread()
{
        int input;
        char c=0;
        while (c<33) c=getchar_unlocked();
        input=0;
        while (c>33)
        {
        input=input*10+c-'0';
        c=getchar_unlocked();
        }
        return input;
}

main()
{
    int n,j,k,test_cases,i;
    test_cases=fastread();
    for(k=0;k<test_cases;k++)
    {
        n=fastread();
        int a[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                a[i][j]=fastread();;
            }
        }

        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<=i;j++)
            {
                if(a[i+1][j]>a[i+1][j+1])
                    a[i][j]+=a[i+1][j];
                else
                    a[i][j]+=a[i+1][j+1];
            }
        }
            printf("%d\n",a[0][0]);

    }
return 0;
}
