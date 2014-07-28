#include<stdio.h>

int fi(int n)
{
       int result=n,i;
       for(i=2;i*i<=n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n>1) result -= result / n;
       return result;
}
main()
{
    int n,test_cases,k,phi,ans,i;
    float maxim,check;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&n);
        maxim=0.5;
        for(i=2;i<=n;i++)
        {
            phi=fi(i);
            check=(float)phi/(float)(i);
            if(check>=maxim)
            {
                maxim=check;
                ans=i;
            }

        }
            printf("%d\n",ans);
    }

return 0;
}
