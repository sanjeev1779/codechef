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
//int arr[3000005];
int freq[1000002];
/*inline int fastRead_int()
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
};*/
main()
{
    freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test_cases;
    S(test_cases);
   //test_cases= fastRead_int();
    LL temp,ans1,ans2,last;
    int N,i,a,b,c,d;
    while(test_cases--)
    {
        S(N);
		memset(freq,0,sizeof(freq));
        //N= fastRead_int();
        scanf("%d %d %d %d",&a,&b,&c,&d);
      // a = fastRead_int(); b= fastRead_int();c= fastRead_int();d= fastRead_int();

		freq[d]++;
		last=d;
		LL maxm=d;
		LL minm=d;
        for(i=1;i<N;i++)
        {
            temp= (a*last*last+ b*last +c)%1000000;
			freq[temp]++;
			last=temp;
			maxm= max(maxm,temp);
			minm=min(minm,temp);
			cout<<temp<<" ";
        }
        cout<<endl;
        int cnt=1,j;
        ans1=0,ans2=0;
        for(i=maxm;i>=minm;i--)
        {
            if(freq[i]>0)
            {

            	if(freq[i]%2) cnt++;
            		if(cnt%2) {
            			ans1=ans1+ i*( (freq[i]+1)/2);
            			ans2= ans2+ i*( freq[i]-(freq[i]+1)/2);
            		}
            		else
            		{
            			ans2=ans2+ i*( (freq[i]+1)/2);
            			ans1= ans1+ i*( freq[i]-(freq[i]+1)/2);
            		}


            }

        }
        if(ans1>ans2) ans1= ans1-ans2;
        else ans1= ans2-ans1;
        printf("%lld\n",ans1);
    }
return 0;
}
