#include<stdio.h>
main()
{
    int test_cases,i,n,L,k,maxm,p,ans;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&L);
        scanf("%d",&maxm);
        p=1;
        for(i=1;i<L;i++)
        {
            scanf("%d",&n);
            if(n>maxm)
            {
                p=0;
                ans=i+1;
                maxm=n;
            }
        }

        if(p==0) printf("%d\n",ans);
        else printf("1\n");
    }

return 0;
}
