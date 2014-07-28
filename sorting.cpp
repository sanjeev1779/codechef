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
int cnt=0;
void quicksort(vector<int>vec)
{
    int l= vec.size();
    if(l<=1) return;
    int pivot= vec[(l-1)/2];
    //cout<<"pivot"<<pivot<<endl;
    vector<int>left,right;
    for(int i=0;i<l;i++)
    {
        cnt++;
        if(vec[i]<pivot)
            left.pb(vec[i]);
        else if(vec[i]>pivot)
            right.pb(vec[i]);
    }
    quicksort(left);
    quicksort(right);
  /*  cout<<"pivot = "<<vec[pivot]<<endl;
    for(i=0;i<left.size();i++)
        cout<<left[i]<<" ";
    cout<<"\n left end\n right \n";
    for(i=0;i<right.size();i++)
        cout<<right[i]<<" ";*/
}
main()
{
    int N;
    S(N);
    int i,x;
    vector<int>vec;
    for(i=0;i<N;i++)
    {
        S(x);
        vec.pb(x);
    }
    quicksort(vec);
    cout<<cnt<<endl;

return 0;
}
