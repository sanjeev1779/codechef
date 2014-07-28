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
    int test_cases,c;
    S(test_cases);
    int x[106],l[106];
    int N,i,j;
    while(test_cases--)
    {
        S(N);
        for(i=0;i<N;i++)
        {
            S(x[i]);
            S(l[i]);
        }

        for(j=0;j<N;j++)
        {
            i=j;
            c=1;
            while( (x[i+1]>x[i]) && (x[i+1]< x[i]+l[i]) )
               {
                   c++;
                   i++;
               }
            P(c);
        }


    }

return 0;
}



