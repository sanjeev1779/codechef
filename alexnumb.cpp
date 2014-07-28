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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
      //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
        //freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int n,q,i;
    string ch;
    int n1,n2;
    S(n);S(q);
    int arr[n+10];
    for(i=0;i<n;i++)
        S(arr[i]);
    LL sum=0;


    while(q--)
    {
            cin>>ch;
            S(n1);S(n2);
            if(ch[0]=='S' )
                {
                    sum=0;
                    for(i=n1;i<=n2;i++)
                        sum+=arr[i];
                    printf("%lld\n",sum);
                }
            else if(ch[0]=='G' ){
                    arr[n1]= arr[n1]+n2;

            }
            else
            {
                arr[n1]= arr[n1]-n2;

            }
    }
return 0;
}
