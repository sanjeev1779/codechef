#include<stdio.h>
int gcd(int a, int b)
{
    int temp;
    temp = a%b;
    if(temp==0)
        return(b);
    else
       return(gcd(b, temp));
}
main()
{
    int i,test_cases,k,n,j,p,phi,ans;
    float maxim,check;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&n);
        maxim=0.50;
        for(i=2;i<=n;i++)
        {
            phi=0;
            j=i;
            for(p=1;p<=j;p++)
            {
               // printf("gcd= %d\n",gcd(j,p));
                if(gcd(j,p)==1)
                    phi=phi+1;
            }
           //printf("%d\n",phi);
            check=(float)phi/(float)(i);

                printf("%f\n",check);
           //printf("%d %f\n",phi,check);
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
