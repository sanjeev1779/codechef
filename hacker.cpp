#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    int i,l;
    int odd=0;
    string ch;
    cin>>ch;
    l= ch.size();
    int a[26];
    memset(a,0,sizeof(a));
    for(i=0;i<l;i++)
    {
        a[ch[i]-97]++;
    }

    for(i=0;i<26;i++)
    {
        if(a[i]%2==1)
            odd++;
    }
    if(odd==0 || odd==1)
        printf("YES\n");
    else
        printf("NO\n");

return 0;
}
