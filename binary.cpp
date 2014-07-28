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
    int n,i;
    cin>>n;
    int p;
    vector<int>vec;
    for(i=0;i<n;i++)
    {
      S(p);
      vec.pb(p);

    }
    int rem;
    cin>>rem;
    int x= binary_search(vec.begin(),vec.end(),rem);
     if(x==1)
        cout<<"yes\n";
     else cout<<"no\n";

return 0;
}
