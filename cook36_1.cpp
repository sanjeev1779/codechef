#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define LL long long
using namespace std;
main()
{

    int test_cases;
    LL i;
    int d;
    LL N,D;
    cin>>N>>D;
    LL L[N];
    for(i=0;i<N;i++)
    {
        cin>>L[i];
    }
    LL ans=0;
    sort(L,L+N);
    for(i=0;i<N-1;)
    {
        if(L[i+1]-L[i]<=D)
        {
            i++;
            ans++;
        }
        i++;
    }
    cout<<ans<<endl;

return 0;
}
