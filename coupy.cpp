#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;
main()
{
    int N,L,i,R,K,Q;
    scanf("%d %d",&N,&Q);
    int a[N+2];
    int ans=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
    }
    while(Q--){
    scanf("%d %d %d",&L,&R,&K);
    ans=0;
        for(i=L;i<=R;i++)
        {
            if(a[i]%K==0)
                ans++;
        }
    printf("%d\n",ans);
    }

return 0;
}
