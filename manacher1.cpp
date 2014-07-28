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
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  int start=0;
  cout<<T<<endl;
  string str1;
  int st;
  for (int i = 1; i < n-1; i++) {
    start=i;
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
    // find the palindromic substring
    //string str1= s.substr(start,P[i]);
    //cout<<"i = "<<start<<" : "<<str1<<endl;
    if(i%2==0)
    {
        st= start/2-1;
        if(P[i]%2==1)//odd
            st= st-P[i]/2;
      str1=   s.substr(st,P[i]);
        cout<<"palindrome "<<(start/2-1)<<" : "<<str1<<endl;
    }
   // cout<<"i = "<<start<<" : "<<P[i]<<endl;

  }//

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
        cout<<i<<" :: "<<P[i]<<endl;
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  cout<<"sdknsakndk"<<endl;
  for(int i=0;i<s.size();i++)
  {
      cout<<i<<" : "<<(2*P[i]-1)<<endl;
  }
  delete[] P;

  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

main()
{
        //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
        //freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        string str;
        cin>>str;
        cout<<longestPalindrome(str)<<endl;
return 0;
}
