#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    int test_cases,L,l2,l1,i,j;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        char str1[200001],str2[200001];
        scanf("%s %s",str1,str2);
        //cin>>str2;
        cin>>L;
        l1= strlen(str1);
        l2=strlen(str2);
        int c=0;
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(str1[i]==str2[j])
                    c++;
            }
        }
        printf("%d ",c);
        for(i=0;i<L-1;i++)
            printf("0 ");
        printf("\n");

    }
return 0;
}
