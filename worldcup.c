#include<stdio.h>
main()
{
    int test_cases,a1,a2,a3,a4,ways,k,run;
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%d",&run);
        ways=0;
        for(a1=run;a1>=0;a1-=6)
        {
            for(a2=a1;a2>=0;a2-=4)
            {
                for(a3=a2;a3>=0;a3-=2)
                {
                    ways++;
                }
            }
        }

        printf("%d\n",ways);
    }

return 0;
}
