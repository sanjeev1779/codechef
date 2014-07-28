#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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

int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test_cases;
   // S(test_cases);
   test_cases= fastRead_int();
    LL temp,ans1,ans2;
    int N,i,a,b,c,d;
    while(test_cases--)
    {
        //S(N);
        N= fastRead_int();
       // scanf("%d %d %d %d",&a,&b,&c,&d);
       a = fastRead_int(); b= fastRead_int();c= fastRead_int();d= fastRead_int();
        int arr[N+5];
        arr[0]=d;
        for(i=1;i<N;i++)
        {
            temp=arr[i-1];
            arr[i]= (a*temp*temp+ b* temp+c)%1000000;
        }
        sort(arr,arr+N);
        int cnt=1;
        ans1=0,ans2=0;
        for(i=N-1;i>=0;i--)
        {
            if(cnt%2)
            {
                ans1+=arr[i];
            }
            else ans2+=arr[i];
            cnt++;
        }
        ans1= abs(ans1-ans2);
        printf("%lld\n",ans1);
    }
return 0;
}
