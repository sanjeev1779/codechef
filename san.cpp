#include<stdio.h>
main()
{
    int t,num,i;
    scanf("%d",&t); //number of test cases


    for(i=0;i<t;i++)
    {
        int ans=0;
        scanf("%d",&num);

        //calcuation of num of zeroes
        int div=5;
        while(div<=num)
        {
            ans= ans+ num/div;
            div=div*5;
        }

        printf("%d\n",ans);
    }

return 0;
}
