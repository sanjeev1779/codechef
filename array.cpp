#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
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
LL gcd(LL a, LL b){ LL temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int main()
{
  int t,n;
  cin>>t;

  {
     while(t--){
		cin>>n;
		if(n%2 == 0)
		cout<<"Valar Morghulis\n";

		else
		cout<<"Lannisters always pays their debts\n";
	}
  }

return 0;
}
