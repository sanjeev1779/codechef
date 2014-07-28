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

int check_prime(int num)
{
    int i;
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
              return 0;
        }
    }
    return 1;
}
int isprime(LL num)
{
    LL i;
    LL temp=num,pnum;
    int count = 0,flag=0;
    if(num==1)
        return 0;
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
            flag++;
        if(flag>1)
            break;
        while(num%i==0)
        {
            pnum=i;
            num/=i;
            count++;
        }
    }
    if(num!=1)
    {
        if(num==pnum)
            count++;
        else
            flag++;
    }
     // cout<<"temp= "<<temp<<" and count = "<<count<<"flag ="<<flag<<endl;
    if(flag>1)
        return 0;
    if(check_prime(count+1))
        return 1;
    return 0;
}
main()
{
    LL i,L,R;
    int test,count,special;

    S(test);
    while(test--)
    {
        special = 0;
        scanf("%lld %lld",&L,&R);
        for(i=L;i<=R;i++)
        {
           // printf("hi.. %lld= %d\n",i,isprime(i));
           if(isprime(i)==1)
            {
                special++;

            }
        }
        printf("%d\n",special);
    }

return 0;
}
