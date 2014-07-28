#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#define pb push_back
using namespace std;


int ans[1000001][3];
int limit=1000000;
vector<int>prime;
vector<bool> sieve(limit+1, false);
int i,n;
void  sieve_algo()
{

    for (n=4;n<=limit;n=n+2)
    {
        sieve[n]=true; //making odd number false, as they cant be prime
    }
    for(n=3;n*n<=(limit);n=n+2)
    {
        if(!sieve[n])
        {
            for(int m=n*n;m<=limit;m=m+(2*n))
            {
                sieve[m]=true;
            }
        }
    }
    for(i=2;i<=limit;i++)
    {
        if(!sieve[i]) //if sieve[i]=0
          {
              prime.pb(i);
             // cout<<"o= "<<i<<endl;
          }

    }
}

void precompute()
{
    //int a[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

    int i,j,k,num;
    int l= prime.size();
      for(i=0;i<l;i++)
      {
          for(j=0;j<l;j++)
          {
              for(k=0;k<l;k++)
              {
                  num= prime[i]+prime[j]*prime[j]+ prime[k]*prime[k]*prime[k];
                  if(num<1000001){
                  ans[num][0]=prime[i];
                  ans[num][1]=prime[j];
                  ans[num][2]=prime[k];
                  }
                  else
                    break;
              }
          }
      }
}
main()
{
    sieve_algo();
    precompute();
    int x;
    while(1)
      {
          scanf("%d",&x);
          if(x!=0)
            printf("%d %d %d\n",ans[x][0],ans[x][1],ans[x][2]);
          else
            break;
      }

return 0;
}
