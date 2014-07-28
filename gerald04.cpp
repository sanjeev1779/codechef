#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<sstream>
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
int convertString(string s){int num;stringstream sstr(s);sstr>>num;return num;}
main()
{
     // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test,dist,time1,time2,x,y;
    double ans1,ans2;
    S(test);
    string str1,str2;
    while(test--){
    scanf("%d:%d",&x,&y);
    time1= x*60 + (y);
    scanf("%d:%d",&x,&y);

    time2= (x)*60 + y;
    S(dist);
    double diff= time1-time2;
     ans1= time1-time2+dist;
     printf("%.1lf ",ans1);
     ans2=0.0;
     if(2*dist>=diff)
     {
         ans2+= (2*dist-diff)*1.0/2.0;
     }
     ans2+=diff;
     printf("%.1lf\n",ans2);
    }
return 0;
}
