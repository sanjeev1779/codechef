#include<stack>
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
main()
{
        //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int test_cases;
      S(test_cases);
      string str,ans;
      int i,l;
      while(test_cases--)
      {
          ans="";
          cin>>str;
          stack<char>brac;
          stack<char>op;
          l= str.length();
          for(i=0;i<l;i++)
          {
              if(str[i]=='(')
              {
                  brac.push('(');
              }
              else if(str[i]==')')
              {
                  brac.pop();
                  ans+=op.top();
                  op.pop();
              }
              else if(str[i]>='a'&& str[i]<='z')
              {
                  ans+=str[i];
              }
              else  op.push(str[i]);
             // cout<<ans<<endl;
          }
          cout<<ans<<endl;
      }
return 0;
}
