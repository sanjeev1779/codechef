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
LL mod= 1000000007;
int cnt(LL num)
{
    int c=0;
    while(num>0)
    {
        num/=10;
        c++;
    }
    return c;
}
LL get_num(int c)
{
    LL num=0;
    while(c>0)
    {
        num=num*10+9;
        c--;
    }
    return num;
}


main()
{
    int test;
    S(test);
    LL ly,lx, left1,left2,right1,temp1,temp2,l,r,sum=0;
    while(test--)
    {
        scanf("%lld %lld",&l,&r);
        lx= cnt(l);
        ly =cnt(r);
        sum=0;
        if(lx!=ly){
         left1=  get_num(lx);
            right1= get_num(ly);
            temp1= (left1*(left1+1)/2 )%mod;
            temp2= (((l-1)*l)/2)%mod;
            sum= (sum+((temp1%mod- temp2%mod+ mod)*lx)%mod)%mod;
            lx++;
        while(lx<ly)
        {
            left1=  get_num(lx);
            temp1= (left1*(left1+1)/2 )%mod;
            left2=  get_num(lx-1);
            temp2= (left2*(left2+1)/2 )%mod;
            sum= (sum+((temp1%mod- temp2%mod+ mod)*lx)%mod)%mod;
            lx++;
        }
        left1= get_num(lx-1);
        temp1= (left1*(left1+1)/2 )%mod;
        temp2= (r*(r+1)/2)%mod;
        sum= (sum+((temp2%mod- temp1%mod+ mod)*lx)%mod)%mod;}
        else {
                temp1= (r*(r+1)/2)%mod;
                temp2= (l*(l-1)/2)%mod;
                sum= (sum+((temp1%mod- temp2%mod+ mod)*lx)%mod)%mod;
        }
        printf("%lld\n",sum%mod);
    }
return 0;
}
