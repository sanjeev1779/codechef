#include <stdio.h>
#define LL long long
#define MOD 1000000007

int modular_pow(int base, int exponent, int modulus)
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

LL modular_pow1(LL a,LL d,LL mod)
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

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int upper, d, m, n;
		int x1, x2, x3;
		int limit;
		int pow[50], i;
		long long count;
		scanf("%d%d%d%d", &upper, &d, &m, &n);
		limit = (upper < n ? upper : n - 1);
		for (i = 0; i <= limit; ++i)
			pow[i] = modular_pow(i, d, n);
		count = 0;
		for (x1 = 0; x1 <= limit; ++x1)
			for (x2 = 0; x2 <= limit; ++x2)
				for (x3 = 0; x3 <= limit; ++x3)
					if ((pow[x1] + pow[x2] + pow[x3]) % n == m)
					{
						//printf("(%d, %d, %d)\n", x1, x2, x3);
						long long  c1 = upper / n + (x1 <= (upper % n));
						long long  c2 = upper / n + (x2 <= (upper % n));
						long long  c3 = upper / n + (x3 <= (upper % n));

						long long tmp = ((c1 % MOD) * (c2 % MOD)) % MOD;
						tmp = (tmp * (c3 % MOD)) % MOD;
						count = (count + tmp) % MOD;
					}
		printf("%lld\n", count);
	}
	return 0;
}
