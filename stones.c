#include<iostream>
#include<string.h>
using namespace std;
main()
{
    int test_cases,i,j,ans,lj,ls;
    cin>>test_cases;
    char J[1005];
    char S[105];
    int a[125];
    while(test_cases--)
    {
        ans=0;
        cin>>J;
        cin>>S;
        memset(a,0,sizeof(int)*125);
        lj=strlen(J);
        ls=strlen(S);
        for(i=0;i<lj;i++) //counting the total numbers of char of S
        {

                a[J[i]]++;
        }

        for(j=0;j<ls;j++)
        {
            if(a[S[j]]>0)
            {
                    ans++;
            }
        }

        cout<<ans<<endl;
    }

return 0;
}
