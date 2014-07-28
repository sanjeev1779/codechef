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
void permutation(string str,int i)
{
    int l= str.size();
    if(i==l)
        cout<<str<<endl;
    for(int j=i;j<l;j++)
    {
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[j],str[i]);
    }
return;
}
main()
{
    int t;
    string str;
    S(t);
    while(t--)
    {
        cin>>str;
        permutation(str,0);
    }

return 0;
}
