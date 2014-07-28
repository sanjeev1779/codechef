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
using namespace std;
main()
{
    int N,test_cases,i,j,flag;
    S(test_cases);
    char S[11];
    while(test_cases--)
    {
        scanf("%s",S);
        i=0;
        j= strlen(S)-1;
        flag=1;
        while(i<j)
        {
            if(S[i]!=S[j])
            {
                flag=0;
                break;
            }
            i++;
            j--;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }

return 0;
}
