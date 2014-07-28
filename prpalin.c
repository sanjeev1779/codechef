#include<stdio.h>
#include<math.h>
int ispalin(int num)
{
    int org_num=num,rev=0;
    while(num>0)
    {
        rev=10*rev+num%10;
        num=num/10;
    }

    if(rev==org_num)
        return 1;
    else return 0;
}

int prime(int num)
{
    int p=1,j;
     int sqr_num=pow(num,0.5)+1;
        for(j=2;j<=sqr_num;j++)
        {
            if(num%j==0)
             {
              p=0;
              break;
             }
        }
        if(p==1) return 1;
        else return 0;
}

main()
{
    int num;
    scanf("%d",&num);
    while(1)
    {

        if(ispalin(num))
        {
            if(prime(num))
            {
                printf("%d\n",num);
                break;
            }
        }
    num=num+1;
    }

return 0;
}
