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
map<string,int>first;
map<char,int>::iterator it;
main()
{
    first["san"]=2;
    first["sapmkmsak"]=5;
    first["sannjee"]=6;
    cout<<first.size()<<endl;
    first.erase("san");
    cout<<first.size()<<endl;
    bool x= first.empty();
    cout<<x<<endl;
    //it= first.find("san");
    if(first.find("san")== first.end())
        cout<<"san is not prestn\n";
    else cout<<"presnet";
    cout<<first["sannjee"]<<endl;
return 0;
}
