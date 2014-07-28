#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;

LL fast_pow(LL a,LL d,LL mod)
{
  LL mul=1;
    while(d>0)
    {
      switch(d%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      d/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (LL) (mul%mod);
}

LL fast_pow2(LL a,LL d, LL mod)
{

    LL mult=1;
    while(d>0)
    {
        if(d%2==1)
            mult= (mult*a)%mod;
        a= (a*a)%mod;
        d=d/2;
    }

    return (mult%mod);

}
main()
{

    LL i,j,k,n;
    LL upper,d,val,soln,minm,sol,m;
    int test_Cases,ans;
    cin>>test_Cases;
    LL a[41]={0};
    while(test_Cases--)
    {
         LL a[41]={0};
        sol= 0;
        vector<int>first,second,third;
            cin>>upper>>d>>m>>n;
        if(d>0)
        {
            int ans=0;
            minm=  (upper>n)?n:upper;

            for(i=0;i<n;i++)
            {
                cout<<" upper/n= "<<upper%n;
                if(i<=upper%n)
                {
                      cout<<" upper/n= "<<upper/n;
                    a[i]= (upper/n) +1  ;
                    printf(" %d = %d\n",i,a[i]);
                }
                else
                   {

                   a[i]= upper/n;
                   printf(" %d = %d\n",i,a[i]);}
            }
            cout<<" d= "<<d<<endl;
            for(i=0;i<n;i++)
                printf(" %d = %d\n",i,a[i]);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(k=0;k<n;k++)
                    {

                       // printf("i=  %d d= %d m=%d =%lf \n",i,d,m, fast_pow(i,d,m));
                        //printf("j=  %d d= %d m=%d =%lf \n",j,d,m, fast_pow(j,d,m));
                        //printf("k=  %d d= %d m=%d =%lf \n",k,d,m, fast_pow(k,d,m));
                        //cout<<"enxt\n";
                        val = fast_pow(i,d,m)+ fast_pow(j,d,m)+  fast_pow(k,d,m);
                       //val = pow(i,d)+pow(j,d)+pow(k,d);
                        if( val %n==m)
                        {
                            //printf("%d %d %d\n",i,j,k);
                            cout<<"sol= "<<sol<<endl;
                            sol+= ( (a[i]%m)*(a[j]%m)*(a[k]%m) )%m;
                            //sol+= (a[i]*a[j]*a[k])%m;
                            ans++;

                        }
                    }
                }
            }
            cout<<"ans= "<<ans<<endl;
            /*for(i=0;i<ans;i++)
            {

                if(first[i]==upper || second[i]==upper || third[i] ==upper)
                    {
                        printf("%d %d %d\n",first[i],second[i],third[i]);
                        soln++;
                    }
            }*/
            cout<<sol<<endl;
        }
        else
        {
            val= 3;
            if(val%n==m)
                ans=1;
            else
                ans=0;
            cout<<ans<<endl;
        }
    }
return 0;
}
