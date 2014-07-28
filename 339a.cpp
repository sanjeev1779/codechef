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
    int i;
    string st;
    cin>>st;
    int l= st.size();
   vector<int>vect;
    for(i=0;i<l;i++)
    {
        if(isdigit(st[i]))
           {
               vect.pb(st[i]-48);
           }
    }
    sort(vect.begin(),vect.end());
    for(i=0;i<vect.size()-1;i++)
    {
        printf("%d+",vect[i]);
    }
    printf("%d\n",vect[vect.size()-1]);

return 0;
}
