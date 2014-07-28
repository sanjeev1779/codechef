#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<sstream>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int lps[10000000];
inline void fastLongInput(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-') {
            neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}

void LPS(string pat)
{
    int len=0; //length of the prev. longest prefix suffix
    int i;
    lps[0]=0;// 1st char has no ps
    i=1;
    int M= pat.size();
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else // if(pat[i]!=pat[len])
        {
            if(len!=0)
            {
                len= lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP_search(string text, string pat)
{
    int N= text.size();
    int M= pat.size();
    LPS(pat);
    int cnt=0;
    int i=0,j=0; //index of text
    while(i<N)
    {
        if(pat[j]==text[i])
        {
            i++;j++;
        }
        if(j==M)
        {
            //printf("pattern starts from %d and ends at %d\n",i-j,i-1);
            cnt++;
            j=lps[j-1];
        }
        else if(pat[j]!=text[i]) // mismatch after j-1 matches
        {
            if(j!=0)
                j=lps[j-1];
            else
            i++;
        }
    }
    printf("%d\n",cnt);
}
main()
{
    int t,i,N,K;
    fastLongInput(t);
    while(t--)
    {
        fastLongInput(N);
        fastLongInput(K);
        string txt="";
        for(i=1;i<=N;i++)
        {
            stringstream ss;
            ss<<i;

            txt+=ss.str();
        }
       // cout<<txt<<"s\n";
        stringstream ss;
        ss<<K;

        string match= ss.str();
      //  cout<<txt<<endl;
        //cout<<match<<endl;
      KMP_search(txt,match);

    }
return 0;
}
