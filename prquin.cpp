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
    int N;
    S(N);
    int i;
    int flag=0;
    string src;
    cin>>src;
    for(i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("YES\n");
    else
        cout<<src<<endl;

return 0;
}
