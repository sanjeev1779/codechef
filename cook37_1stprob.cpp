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
int prime[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401};
main()
{
    int N,L,i,R,K,Q;
    scanf("%d %d",&N,&Q);
    int a[N+2];
    int ans=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        for(j=2;j<=N/2+1;j++)
        {

        }
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
