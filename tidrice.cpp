#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

main()
{
    int test_cases,ans,n,j,i,curr_vote;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n;
        ans=0;
        char name[n][21];
        int vote[n];
        char ch;
        int user_skip[101];
        for(i=0;i<n;i++)
        {
            cin>>name[i]>>ch;
            if(ch=='+')
                vote[i]=1;
            else vote[i]=-1;
        }

        //searching for matching user ids
        for(i=0;i<n;i++)
        {
            if(user_skip[i])
                continue;
            for(j=i;j<n;j++)
            {
                if(strcmp(name[i],name[j])==0)
                {
                    curr_vote=vote[j];
                    user_skip[j]=1;
                }
            }
            ans+=curr_vote;
        }
        cout<<ans<<endl;
    }

return 0;
}
