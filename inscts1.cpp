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
    int test_cases;
    S(test_cases);
    int even,odd,a,b,c;
    while(test_cases--)
    {
        odd=0,even=0;
        S(a);S(b);S(c);
        if(a%2==0)
            even++;
        else
            odd++;
        if(b%2==0) even++;
          else odd++;
        if(c%2==0) even++;
            else odd++;

        if(odd==3 || odd==1 && even==2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }


return 0;
}
