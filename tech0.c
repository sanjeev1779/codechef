#include<stdio.h>
main()
{
    int test_cases,i,n,k,p;
    scanf("%d",&test_cases);
    char w1[22],w2[22];
    int a[26];
    for(k=0;k<test_cases;k++)
    {
        scanf("%s %s",w1,w2);

        for(i=0;i<26;i++)
        {
            a[i]=0;
        }

        int l1=strlen(w1);
        int l2=strlen(w2);
        p=1;
        if(l1==l2)
        {
                        for(i=0;i<l1;i++)
                        {
                            a[w1[i]-97]+=1;
                        }


                        for(i=0;i<l1;i++)
                        {
                            if(a[w2[i]-97]>=1)
                            {
                                a[w2[i]-97]--;
                            }
                            else
                            {
                                p=0;
                                break;
                            }
                        }

                        for(i=0;i<26;i++)
                        {
                            if(a[i]!=0)
                            {
                                p=0;
                                break;
                            }
                        }
        }
        else
        {
            p=0;
        }
        if(p==0)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }

 return 0;
}
