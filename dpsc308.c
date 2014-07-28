#include<stdio.h>
main()
{
    int n,i,j,coun;
    float vr,vl;
    while(1)
    {
        coun=1;
        scanf("%d",&n);
        if(n==0)
        break;
        else if(n==1)
            printf("1/1\n");
        else
        {
            i=1;
            j=1;
            while(1)
            {
                vl=i/(i+j);
                coun++;
                if(coun==n)
                {
                    printf("%d/%d\n",i,i+j);
                    break;
                }
                vr=(i+j)/i;
                if(coun==n)
                {
                    printf("%d/%d\n",i+j,j);
                    break;
                }
                i++;
                j++;
            }
        }
    }

return 0;
}
