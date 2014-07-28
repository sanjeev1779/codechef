#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
#define MOD 1000000007
#define inf 1000000007
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

LL modular_pow(LL base, LL exponent, LL modulus)
{
	LL result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}
main()
{

    LL i,j,k,n;
    LL upper,d,val,soln,minm,sol,count,m;
    int test_Cases;
    cin>>test_Cases;
    while(test_Cases--)
    {
         LL a[41];
         count=0;
         cin>>upper>>d>>m>>n;
        if(upper< n)
            minm= upper;
        else
            minm= n-1;


            for(i=0;i<=minm;i++)
            {

                if( i<=(upper%n)&& (upper%n)>0)
                {

                    a[i]= (upper/n) +1  ;

                }
                else
                   {a[i]= upper/n;
                   }
        }

            for(i=0;i<=minm;i++)
            {
                for(j=0;j<=minm;j++)
                {
                    for(k=0;k<=minm;k++)
                    {

                        val =  modular_pow(i,d,n)+ modular_pow(j,d,n)+  modular_pow(k,d,n);
                       //val = pow(i,d)+pow(j,d)+pow(k,d);
                        if( val %n==m)
                        {
                            //printf("%d %d %d\n",i,j,k);
                            //cout<<"sol= "<<sol<<endl;
                            //sol = ((a[i] % MOD) * (a[j] % MOD)) % MOD;
						//sol = (sol * (a[k] % MOD)) % MOD;
						//count = (count + sol) % MOD;
						int x= (i <= (upper % n));
						long long  c1 = upper / n + x;
						cout<<"1st "<<x<<endl;
						long long  c2 = upper / n + (j <= (upper % n));
						long long  c3 = upper / n + (k <= (upper % n));

						long long tmp = ((c1 % MOD) * (c2 % MOD)) % MOD;
						tmp = (tmp * (c3 % MOD)) % MOD;
						count = (count + tmp) % MOD;

                        }
                    }
                }
            }
		count=count%inf;
            cout<<count<<endl;

    }
return 0;
}
