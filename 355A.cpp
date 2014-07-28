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
    int k,d,i;
    S(k);
    S(d);
    if(d==0 && k>1)
        printf("No solution\n");
    else
    {
        printf("%d",d);
        for(i=0;i<k-1;i++)
            cout<<"0";
        cout<<endl;
    }


return 0;
}
