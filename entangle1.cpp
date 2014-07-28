#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
main()
{
    int test,i,j,ans,L,l1,l2;
    cin>>test;
    while(test--)
    {
        char str1[200001],str2[200001];
        scanf("%s %s",str1,str2);
        //cin>>str2;
        ans=0;
        cin>>L;
        int a[26]={0};
        int b[26]={0};
        l1= strlen(str1);
        l2=strlen(str2);
        int c=0;

        for(i=0;i<l1;i++)
        {
            a[str1[i]-97]++;
        }
        for(i=0;i<l2;i++)
            b[str2[i]-97]++;
        for(i=0;i<26;i++)
        {
            if(a[i]<b[i])
            ans+=a[i];
            else
                ans+=b[i];
        }
        printf("%d ",ans);
        for(i=0;i<L-1;i++)
            printf("0 ");
        printf("\n");

    }
return 0;
}

