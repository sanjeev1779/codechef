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
int gcd(int a, int b)
{
    int c;
    while(b>0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
main()
{
    int test_cases;
          int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691};

    S(test_cases);
    int a,n,gc;
    int flag,i,ans;
    while(test_cases--)
    {
        S(n);
        S(a);
        gc=a;
        while(n-->1)
        {
            S(a);
            gc= gcd(gc,a);
        }

      //  printf("%d\n",gc);
        flag=0;
        if(gc>1)
        {
            for(i=0;primes[i]*primes[i]<=gc;i++)
            {
                if(gc%primes[i]==0)
                {
                    printf("%d\n",primes[i]);
                    flag=1;
                    break;

                }
            }
            if(flag==0)
                printf("%d\n",gc);
        }
        else printf("-1\n");

    }

return 0;
}
