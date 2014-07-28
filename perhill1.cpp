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
    int test_Cases;
    S(test_Cases);
    LL h;
    int flag,c;
    LL i;
    double base;
    while(test_Cases--)
    {
        scanf("%d",&c);
        h=c*c;
        flag=1;
       for(i=1;i*i<h;i++)
        {
            base= sqrt(h-i*i);
            if( ceil(base)-floor(base)==0)
            {
                flag=0;
             //cout<<base<<"::"<<i<<endl;
                break;
            }
        }
        if(flag==0)
            printf("PERFECT\n");
        else
            printf("IMPERFECT\n");
    }


return 0;
}
