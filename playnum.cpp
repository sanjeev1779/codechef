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
    int test_cases;
    S(test_cases);
    int n,q,i,x,y;
    LL sum;

    while(test_cases--)
    {

        sum=0;
        S(n);
        S(q);
        int a[n+1];
        int arr[n+1];
        memset(arr,0,sizeof(arr));
        for(i=0;i<n;i++)
        {
            S(a[i]);
        }

        while(q--)
        {
            S(x);
            S(y);
            x--;
            y--;
            for(i=x;i<=y;i++)
            {
                arr[i]++;
            }
        }
        sort(arr,arr+n);
        sort(a,a+n);

        for(i=n-1;i>=0;i--)
        {
            sum+= a[i]*arr[i];
        }
        cout<<sum<<endl;
    }

return 0;
}
