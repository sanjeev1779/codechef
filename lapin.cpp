#include<stdio.h>
#include<string.h>
main()
{
    int test_cases,flag,i,l,ran,x;
    scanf("%d",&test_cases);
    int a[127];
    while(test_cases--)
    {
        flag=1;
        char w[1005];
        scanf("%s",&w);
        memset(a,0,sizeof(a));
        l=strlen(w);

        ran=l/2;
        x=ran;
        if(l%2!=0)
        {
                x=ran+1;
        }
        for(i=0;i<ran;i++)
        {

            a[w[i]]++;
        }

        for(i=x;i<l;i++)
        {
            if(a[w[i]]>0)
            {
                a[w[i]]--;
            }
            else
            {
                flag=0;
                break;
            }
        }


        if(flag==1)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }

return 0;
}
