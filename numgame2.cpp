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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4==1)
            cout<<"ALICE\n";
        else
            cout<<"BOB\n";
    }

return 0;
}
