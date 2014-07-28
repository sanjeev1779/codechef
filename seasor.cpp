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

inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};


main()
{
    int test_cases,i,j,k,st_ind, end_ind,n,p;
    //scanf("%d",&test_cases);
    test_cases= fastRead_int();
    int a[1001];
    while(test_cases--)
    {
        vector<int>ans(0);
        j=0;
        //scanf("%d %d",&n,&k);
        n=fastRead_int();
        k=fastRead_int();
        for(i=1;i<=n;i++)
        {
            //scanf("%d",&a[i]);
            a[i]=fastRead_int();
        }

        while(1)
        {
            p=1;
                for(i=1;i<n;i++)
                {
                    if(a[i+1]<a[i])
                    {
                        p=0;
                        st_ind= max(i-k+2,1);
                        end_ind= min(i+2,n+1);
                        sort(a+st_ind, a+end_ind);
                        ans.push_back(st_ind);
                    }
                }
                if(p==1)
                    break;
        }

        int q_size= ans.size();
        printf("%d\n",q_size);
        for(i=0;i<q_size;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
return 0;
}
