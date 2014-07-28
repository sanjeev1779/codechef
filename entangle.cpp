#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
main()
{
    int test_cases,i,j,ans,L,l1,l2;
    cin>>test_cases;
    while(test_cases--)
    {
        char str1[200001],str2[200001];
       // scanf("%s %s",str1,str2);
       cin>>str1>>str2;
        //cin>>str2;
        ans=0;
        cin>>L;
        int a[27];
        memset(a,0,sizeof(a));
        int b[27];
        memset(b,0,sizeof(b));
        l1= strlen(str1);
        l2= strlen(str2);
        int c=0;
    if(L==1){
        for(i=0;i<l1;i++)
        {
            a[str1[i]-97]++;
        }
        for(i=0;i<l2;i++)
        {
            b[str2[i]-97]++;
        }
        for(i=0;i<26;i++)
        {

            ans=ans+ b[i]*a[i];
        }
        printf("%d\n",ans);
    }
    else
    {
         for(i=0;i<L;i++)
            printf("0 ");
            printf("\n");
    }
    }
return 0;
}
