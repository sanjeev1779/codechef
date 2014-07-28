#include<iostream>
#include<math.h>
#define LL long long
#define inf 1000000007
#define MOD 1000000007

using namespace std;
int modular_pow1(int base, int exponent, int modulus)
{
	int result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}
int modular_pow(int a, int b, LL m)
{

    LL mult= 1 ;
    while(b>0)
    {
        if(b%2==1)
            mult= (mult*a)%m;
        a= (a*a)%m;
        b/=2;
    }
    return mult;
}
main()
{
    int t,i,j,k;
    int upper,d;
    int a[50];
    cin>>t;
    int m,n,minm;
    LL temp,ans;
    LL rem[41];
    while(t--)
    {
        cin>>upper>>d>>m>>n;
        LL count=0;
        minm= upper<(n)? upper:(n-1);
        for(i=0;i<=minm;i++)
        {
            a[i]= modular_pow(i,d,n);
        }
        ans=0;
        for(i=0;i<=minm;i++)
        {
            /*if( i<= (upper%n) && (upper%n) > 0)
                rem[i]= (upper/n)+1;
            else
                rem[i]= (upper/n);*/

              rem[i]= (i <= (upper % n));
        }
        for(i=0;i<=minm;i++)
        {

            for(j=0;j<=minm;j++)
            {
                for(k=0;k<=minm;k++)
                {
                    if(  (a[i]+a[j]+a[k])%n == m)
                    {
                        // i,j,k is the soln;
                      // temp=  (rem[i]*rem[j])%inf;
                        //temp = (temp* (rem[k]) )%inf;
                        //ans= ans+ temp;
                     long long c1= (upper/n) + (i<=(upper%n));
                         long long c2= (upper/n) + (j<=(upper%n));
                       long  long c3= (upper/n) + (k<=(upper%n));
                         temp=  ((c1%inf)*(c2%inf))%inf;
                        temp = (temp* (c3%inf) )%inf;
                        ans= (ans+ temp)%inf;
                     /*   long long  c1 = upper / n + (i <= (upper % n));
						long long  c2 = upper / n + (j <= (upper % n));
						long long  c3 = upper / n + (k <= (upper % n));

						long long tmp = ((c1 % MOD) * (c2 % MOD)) % MOD;
						tmp = (tmp * (c3 % MOD)) % MOD;
						count = (count + tmp) % MOD;*/
                    }
                }
            }
        }
        cout<<(ans%inf)<<endl;
    }
return 0;
}
