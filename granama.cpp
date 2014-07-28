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
    int test_cases;
    int a[26];
    int b[26];
    int i,l1,l2;
    cin>>test_cases;
    string st1,st2;
    while(test_cases--)
    {
        cin>>st1;
        cin>>st2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        l1 = st1.size();
        l2 = st2.size();
        for(i=0;i<l1;i++)
        {
            a[ st1[i]-97]++;
        }

        for(i=0;i<l2;i++)
        {
            b[ st2[i]-97]++;
        }
        int p=1; //yes
        for(i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                p=0; //no
                break;
            }
        }

        if(p==0)
        {
            for(i=0;i<26;i++)
            {
                if(a[i]>0 || b[i]>0)
                {
                    if(a[i]>0 && b[i]==0 || b[i]>0 && a[i]==0)
                    {
                        p=1;
                    }
                    else
                    {
                        p=0;
                        break;
                    }
                }
            }
        }



        if(p==1)
            printf("YES\n");
        else
            printf("NO\n");

    }
return 0;
}
