#include<stdio.h>
#include<string.h>
using namespace std;
main()
{
    int test_cases,i,j,ans,lj,ls;
    scanf("%d",&test_cases);
    char J[1005];
    char S[105];
    int a[125];
    while(test_cases--)
    {
        ans=0;
        scanf("%s",J);
        scanf("%s",S);
        memset(a,0,sizeof(int)*125);
        lj=strlen(J);
        ls=strlen(S);
        for(i=0;i<ls;i++) //counting the total numbers of char of S
        {

                a[S[i]]++;
        }

        for(j=0;j<lj;j++)
        {
            if(a[J[j]]>0)
            {
                    a[J[j]]--;
                    ans++;
            }
        }

        printf("%d\n",ans);
    }

return 0;
}
