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
int cnt=0,l;
vector<int>vl,vg,v,temp;
void concat(vector<int>vl,int pivot, vector<int>vg)
{
        vl.pb(pivot);
        int i;
        for(i=0;i<vg.size();i++){
            vl.pb(vg[i]);
        }
}
void quickSort(vector<int>v)
{
    int i;
    l=v.size();
     int pivot = (l+1) / 2;
    for(i=0;i<l;i++)
    {
        cnt++;
        if(v[i]<v[pivot])
        {
            vl.pb(v[i]);
        }
        else
            vg.pb(v[i]);
    }
    concat(quickSort(vl),pivot,quickSort(vg));
}

main()
{
    int n,x,i;
    S(n);
    vector<int>v;
    for(i=0;i<n;i++)
       {
           x=S(n);
           v.pb(x);
       }
    quickSort(v);
    for(i=0;i<n;i++)
        cout<<v[i]<<endl;
        cout<<cnt<<endl;

return 0;
}
