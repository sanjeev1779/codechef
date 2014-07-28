#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
main()
{
    int test_cases,i,ans,rem;
    cin>>test_cases;
    char n[100009];
    while(test_cases--)
    {
        scanf("%s",n);
        ans=0;
        int l=strlen(n);
        for(i=0;i<l;i++)
        {
            if(n[i]!='4' && n[i]!= '7')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }

return 0;
}
