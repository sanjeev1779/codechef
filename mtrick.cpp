#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL unsigned long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;

LL scan()
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
void out(LL n) {
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
 //       freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int Test,i,j;
        LL A,B,C,X,N;
        S(Test)
        string str;
        while(Test--)
        {
            N=scan();
            vector<LL>vec;
            vec.pb(0);
            for(i=1;i<=N;i++)
                {
                    X=scan();
                   vec.pb(X);
                }
                A= scan(); B=scan(); C=scan();
                // cout<<A<<" "<<B<<" "<<C<<endl;
                cin>>str;

                for(i=1;i<=N;i++)
                {
                  //  cout<<"hi\n";
                    if(str[i-1]=='A')
                    {
                        for(j=i;j<=N;j++)
                            vec[j]=( vec[j]+A)%C;
                    }
                    else if(str[i-1]=='M')
                    {
                         for(j=i;j<=N;j++)
                            vec[j]=( vec[j]*B)%C;
                    }
                    else
                    {
                        reverse(vec.begin()+i, vec.end());
                    }
                    cout<<vec[i]<<" ";
                }
                printf("\n");
        }
return 0;
}
