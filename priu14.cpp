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
#define mp make_pair
using namespace std;
int get_worth(char ch)
{
    if( ch=='Q' || ch=='J' || ch=='K')
        return 10;
    else if(ch>='1' && ch<='9')
       {
           int x= ch-48;
           return x;
       }
       else if(ch=='A')
            return 1;
    else return -1;
}
main()
{
    int t,x,y;
    S(t);
    string ch1,ch2;
    while(t--)
    {
        cin>>ch1>>ch2;
        if(ch1.size()>1 || ch2.size()>1)
            {printf("INVALID\n");// cout<<"ih\n";
            }
        else {
        x=get_worth(ch1[0]);
        y=get_worth(ch2[0]);
       // cout<<x<<" : "<<y<<endl;
        int cnt=0;
        if(ch1[0]=='A')cnt++;
        if(ch2[0]=='A')cnt++;
        if(ch1[0]=='A' && ch2[0]=='J' || ch1[0]=='A' && ch2[0]=='Q' || ch1[0]=='A' && ch2[0]=='K' || ch1[0]=='J' && ch2[0]=='A' || ch1[0]=='Q' && ch2[0]=='A' ||ch1[0]=='K' && ch2[0]=='A' )
            printf("STAND\n");
        else {
        if(x==-1 || y==-1 )
            printf("INVALID\n");
        else if(x+y<=11 && cnt!=2  || cnt==1)
            printf("HIT\n");
        else printf("STAND\n");
        }
        }
    }


return 0;
}
