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
    char ch[1005];
    int i,n,j;
    scanf("%s",ch);
    int l=strlen(ch);
    int p=1;
    for(i=0;i<l;i++)
    {
        if(65<=ch[i]<=90 )
        {
            p=0;
            for(j=i-1;j>=0;j--)
            {
                while( isalpha(ch[j]) )
                    num= ch[i];
            }
            for(j=i+1;j<)
            for(j=i+1;j<n;j++)
            {
                if(isalpha(ch[i]))
                    break;
                else
                    printf("%d",ch[j]);
            }
        }
        else
        {
            printf("%d",ch[i]);
            int p=1;
            for(j=i+1;j<n;j++)
            {

                if(isdigit(ch[j]))
                    {
                         printf("%d",ch[j]);
                    }
                else
                {
                    printf("9");
                    p=0;
                }
            }
        }
    }
return 0;
}
