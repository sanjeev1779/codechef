#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
#define LL long long
#define mp make_pair
using namespace std;
pair<int,int>p[100001];
main()
{
    int n,k,i,j;
    cin>>n>>k;

    int a[100000];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
        p[i]= mp(a[i],i);
    }
    sort(p,p+n);
    int ans=0;
    for(i=0;i<n;)
    {

        for(j=i+1;j<n;)
        {
            if( p[i].first== p[j].first && p[j].second- p[i].second < k)
                j++;
            else
                break;
        }
        i=j;
        ans++;
    }
    cout<<ans<<endl;
return 0;
}
