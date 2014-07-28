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
    int n;
    int x;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
       {
           S(x);
            a.pb(x);
        }
    int key;
    cin>>key;
    int found=binary_search(a.begin(),a.end(),key);
    cout<<found<<endl;


return 0;
}
