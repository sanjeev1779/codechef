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
    int test_cases,HT1,MT1,ST1,MT2,HT2,ST2;
    S(test_cases);
    int total_sec;
    while(test_cases--)
    {
        scanf("%d %d %d %d %d %d",&HT1,&MT1,&ST1,&HT2,&MT2,&ST2);
        total_sec= (HT2-HT1)*3600 + (MT2-MT1)*60+ (ST2-ST1);
        total_sec%=400;
        if(total_sec >=0 && total_sec<100)
            printf("S\n");
        if(total_sec>=100 && total_sec<200)
            printf("C\n");
        if(total_sec>=200 && total_sec<300)
            printf("S\n");
        if(total_sec>=300 && total_sec<400)
            printf("C\n");


    }


return 0;
}
