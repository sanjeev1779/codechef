#include<string.h>
#include<stdio.h>
main()
{
    char ct[10000000],fm[10000000];
    int a[27],i,test_cases,k,n;
    char m[40000],f[40000],c[40000];
    int b[27];
    scanf("%d",&test_cases);
    for(k=0;k<test_cases;k++)
    {
            for(i=0;i<26;i++)
            {
                a[i]=0;
                b[i]=0;
            }

            scanf("%s %s",m,f);
            scanf("%d",&n);
            strcpy(ct,"");
            for(i=0;i<n;i++)
            {
                scanf("%s",c);
                strcat(ct,c);
            }
           // printf("ct=%s\n",ct);
            strcat(m,f);
           // printf("fm=%s\n",m);
            for(i=0;i<strlen(m);i++)
            {
                        a[m[i]-97]+=1;
            }

            for(i=0;i<strlen(ct);i++)
            {
                        b[ct[i]-97]+=1;
            }

        //ct is a subsequence of fm
        int p=1;
            for(i=0;i<26;i++)
            {
                if(b[i]>a[i])
                {
                   p=0;
                    break;
                }
            }

          if(p==0)
                printf("NO\n");
          else printf("YES\n");



    }
return 0;
}
