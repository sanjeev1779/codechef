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
vector<int>v;
main()
{
    int n,i,x;
    while(1)
    {
        S(n);
        if(n!=0)
        {
            v.clear();
            for(i=1;i<=n;i++)
            {
                v.pb(i);
            }
            if(n==1 || n==2){
                printf("%d\n",n);
                continue;
                }
            while(v.size()>3)
            {
                v.erase(v.begin()+0);
                x=v[0];
                v.pb(x);
                v.erase(v.begin()+0);
            }
            printf("%d: %d\n",n,v[1]);
        }
        else
            break;
    }

return 0;
}
