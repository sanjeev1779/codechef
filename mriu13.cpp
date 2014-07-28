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
    string str;
    int i;
    cin>>str;
    int l= str.size();
    for(i=0;i<l;i++)
    {
        int x= str[i];
        printf("%c",x-7);
    }
    cout<<endl;

return 0;
}
