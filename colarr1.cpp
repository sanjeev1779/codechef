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
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
int col[1005], B[1005][1005],C[1005][1005];
int scan()
{
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return t;
}
void out(int n) {
	if(n<0){
		n=-n;putchar_unlocked('-');
	}
	int i=10;
	char output_buffer[11];
	output_buffer[10]='\n';
	do{
		output_buffer[--i]=(n%10)+'0';n/=10;
	}while(n);
	do{
		putchar_unlocked(output_buffer[i]);
	}
	while(++i<11);
}
main()
{
      //    freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int test_Cases,i,j,sum,maxm,N,M,K,old_val, new_val,gain,k,len,diff;
      S(test_Cases);

      while(test_Cases--)
      {
          sum=0;
        //scanf("%d %d %d",&N,&M,&K);
        N= scan();
        M= scan();
        K= scan();

        for(i=1;i<=N;i++)
        {
            col[i]=scan();
        }

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
               B[i][j]=scan();
        }
        for(i=1;i<=N;i++)
        {
            sum+= B[i][col[i]];
        }
        // cout<<sum<<endl;

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
                C[i][j]=scan();
        }
        vector<int>changed;
        for(i=1;i<=N;i++)
        {
            old_val= B[i][col[i]];
            maxm=-1;
            for(j=1;j<=M;j++)
            {
                new_val= B[i][j]- C[i][j];
                diff= new_val- old_val;
                if(diff>0)
                {
                    maxm= max(maxm,diff);
                }
            }
            if(maxm>0)
            {
                changed.pb(maxm);
            }
        }
        sort(changed.begin(),changed.end());
        len= changed.size();
        gain=0;
        for(i=len-1;i>=0 ; i--)
        {
            if(K>=1)
            gain+= changed[i];
            else break;
            K--;
        }
       // cout<<gain<<endl;
        sum+=gain;
        out(sum);
      }
return 0;
}
