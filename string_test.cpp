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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    string str,str1,str2,str3;
    int l,r;
    cin>>str;
    cin>>l>>r;
    int len= str.size();
    str1= str.substr(0,l-1);
    str2=str.substr(l-1,r-l+1);
    str3=str.substr(r,len);
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
return 0;
}
