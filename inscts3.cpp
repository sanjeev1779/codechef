#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int t,i,l,j,c;
    S(t);
    string str;
    int freq[30];
    while(t--)
    {
        memset(freq,0,sizeof(freq));
        cin>>str;
        l= str.size();
        for(i=0;i<l;i++)
        {
            freq[str[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            c= i+'a';
            if(freq[i]%2)
            {
                for(j=0;j<freq[i];j++)
                {
                    printf("%c",c);
                }
            }
        }
         for(i=0;i<26;i++)
        {
            c= i+'a';
            if(freq[i]%2==0)
            {
                for(j=0;j<freq[i];j++)
                {
                    printf("%c",c);
                }
            }
        }
        printf("\n");
    }

return 0;
}
