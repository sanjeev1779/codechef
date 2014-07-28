#include<stdio.h>

int subseq(char a[25000], char b[25000])
{
    int la,lb,j,i,p;
        la=strlen(a);
        lb=strlen(b);
        p=1;
        for(i=0;i<la;i++)
        {
              p=1;
              for(j=b;j<lb;j++)
              {
                    if(a[i]==b[j])
                    {
                        //printf("1: %c , %c\n", W[i],M[j]);
                          p=0;
                          b=j+1;
                          break;
                    }
              }
                if(p==1)
                {
                     break;
                }
        }

        if(p==0)
            return 1;
 }

 main()
 {
     int k,test_cases,left,right;
    char M[25000],W[25000];
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
        scanf("%s %s",M,W);
        if(strlen(M)<=strlen(W))
            {
                left= subseq(M,W);
            }
         if(strlen(W)<=strlen(M))
            right=subseq(W,M);

        if(left==1||right==1)
            printf("YES\n");
        else
                printf("NO\n");
    }

return 0;
 }
