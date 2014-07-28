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
#define SL(N) scanf("%",&N);
#define pb push_back
#define mp make_pair
using namespace std;

int no_of_Digits(LL num)
{
    int cnt=0;
    while(num>0)
    {
        cnt++;
        num/=10;
    }
    return cnt;
}

LL maxm_number(int d)
{
    LL num=0;
    while(d-->0)
    {
        num=num*10+9;
    }
    return num;
}
LL num_of_numbers(int d)
{
    LL num=9;
    while(d-->1)
    {
        num*=10;
    }
    return num;
}
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    LL w,m,k;
    LL left,maxm_num,cost,can_be_made;
    int nod;
    cin>>w>>m>>k;
    LL ans=0;
    left=w/k;
    nod= no_of_Digits(m);
    //can_be_made= left/nod;
    //cout<<nod<<endl;
    maxm_num=  maxm_number(nod)-m+1;
   //cout<<maxm_num<<endl;
    cost= maxm_num*nod;
    //cout<<cost<<endl;
   // cout<<left<<endl;
    if(left>= cost)
    {
        ans+= maxm_num;
        left-=cost;
        while(1)
        {
            nod++;

            can_be_made= num_of_numbers(nod);
            cost= can_be_made*nod;
           // cout<<"hi "<<nod<<"  : "<<can_be_made<<" : "<<cost<<endl;
            if(left>=cost)
            {
                left-= cost;
                ans+= can_be_made;
            }
            else
            {
                ans+= left/nod;
                break;
            }
        }
    }
    else
        ans= left/nod;
    cout<<ans<<endl;


return 0;
}
