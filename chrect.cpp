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
    int test_cases,M,N,K;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        scanf("%d %d %d",&N,&M,&K);
        if(N==1 && M>2 || M==1 && N>2)
            printf("%d\n",K);
        else if(N==1 && M==1 || N==1 && M==2 || N==2 && M==1)
                printf("0\n");

        else{
            if(K%2==0)
            printf("%d\n",K/2);
            else
                printf("%d\n",K/2+1);
        }
    }
return 0;
}
