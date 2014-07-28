#include<stdio.h>
main()
{
    int test_cases,l,k,coun,rem;
    long long int x,N,ans,i;
    scanf("%d",&test_cases);

    for(k=0;k<test_cases;k++)
    {
        scanf("%lld %d",&N,&l);
        coun=0;
        for(i=1;i<=N;i++)
        {   x=i;
            while(x>0)
            {
                rem=x%10;
                x=x/10;
                if(rem==l)
                {
                    coun=coun+1;
                    break;
                }
            }
        }

        ans=N+coun;
        printf("%lld\n",ans);
    }

return 0;
}
