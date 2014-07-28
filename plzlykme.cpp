#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

LL no_of_digits(LL num)
{
    LL x= ceil(log10(num));
    return x;
}
LL dig(LL num)
{
    LL cnt=0;
    while(num>0)
    {
        num/=10;
        cnt++;
    }
    return cnt;
}
LL pow1(int a, int b)
{
    LL prod=1;
    while(b>0)
    {
        if(b%2==1)
        {
            prod=(prod*a);
        }
        a=(a*a);
        b=b/2;
    }
    return prod;
}
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        LL test_cases,L,D,S,C;
        SL(test_cases);
        LL x,dig_len_lyk,dig_L;
        int ch;
        while(test_cases--)
        {
            ch=0;
            cin>>L>>D>>S>>C;
                    x=S;
            while(D-->1){
                x= x*(1+C);
                if(x>=L)
                 {
                     ch=1; break;
                 }
            }
            if(x>=L) ch=1;

            if(ch==1)
                printf("ALIVE AND KICKING\n");
            else printf("DEAD AND ROTTING\n");
        }
return 0;
}
