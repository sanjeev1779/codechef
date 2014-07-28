#include<stdio.h>
#include<string.h>

main()
{
    int i,test_cases,k,p,lm,lw,b,p1,j;
    char M[25005],W[25005],temp[25005];
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%s %s",M,W);
        lm=strlen(M);
        lw=strlen(W);


        //keep 1st as smaller compared to 2nd one
        if(lm>lw)
        {
            strcpy(temp,W);
            strcpy(W,M);
            strcpy(M,temp);
        }
        lm=strlen(M);
        lw=strlen(W);
        int i=0,j=0,p=1;
       // printf("%d %d\n",lm,lw);
       // printf("%s %s\n",M,W);
        while(i<lm &&j<lw)
        {
            if(M[i]==W[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

                if(i==lm)
                    printf("YES\n");
                else
                    printf("NO\n");
    }

 return 0;

}
