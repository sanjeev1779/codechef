#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
main()
{
    int n,p,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        else{
        int a[n+1];
        p=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[a[i]]!=i)
            {
                    p=0;
                    break;
            }
        }
        if(p==1)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
        }
    }

return 0;
}
