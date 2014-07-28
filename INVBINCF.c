#include<stdio.h>

main()
{
    int i,test_cases,k,p,ans,n,R,up;
    scanf("%d",&test_cases);

    for(k=0;k<test_cases;k++)
    {
        scanf("%d %d",&n,&R);
        up=pow(2,n-1);
        for(k=0;k<=up;k++)
        {
            if((comb(up,k)%R)==0)
            {
                p=0;
                ans=k;
                break;
            }
        }

        if(p==0)
            printf("%d\n",ans);
        else
                printf("-1\n");

    }

 return 0;
}
