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

int  longest_palind_arr[100];
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
  cout<<T<<endl;
  int n = T.length();
  cout<<n<<endl;
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
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
  }//

  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  int idx=0;
  for(int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
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
        cout<<"length of the longest palindrome centerd at i\n";
        for(int i=0;i<str.size();i++)
            cout<< longest_palind_arr[i]<<endl;



return 0;
}
