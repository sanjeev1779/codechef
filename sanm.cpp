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
    int N;
    S(N);
    int odd_odd=0,even_odd=0, even_even=0, odd_even=0;
    while(N--)
    {
        S(a);
        S(b);
        left_sum+=a;
        right_Sum+=b;
        if(a%2==1 && b%2==1)
            odd_odd++;
        else if(a%2==0 && b%2==0)
            even_even++;
        else if(a%2==0 && b%2==1)
            even_odd++;
        else if(a%2==1 && b%2==0)
            odd_even++;

    }
    if(left_sum%2==0 && right_sum%2==0)
        printf("0\n");
    else if(left_sum%2==1 && right_sum%2==1)
    {
       if(even_even>0)
            printf("1\n");
       else
            printf("0\n");
    }
    else if(left_sum%2==0 && right_sum%2==1)
    {
        printf("")
    }



return 0;
}
