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
/*
inline void fastInput(int &x) {

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

inline void fastLongInput(long int &x) {

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

unsigned long long int fast_mod_power(LL a,unsigned int b,LL mod)
{
  LL mul=1;
    while(b>0)
    {
      switch(b%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      b/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (unsigned int )(mul%mod);
}

*/
main()
{
    int test_cases,x,lc,k,i,max_idx;
    S(test_cases);
    int arr[27],enc[27],maxm;
    string freq_seq;
    char secondstring[150010];
    while(test_cases--)
    {
        cin>>freq_seq;
       // cin>>secondstring;
       getchar();
        gets(secondstring);

        memset(enc,0,sizeof(enc));
        memset(a,0,sizeof(a));
        pair<int,int>p[26];
        lc= strlen(secondstring);
        for(i=0;i<lc;i++)
        {
            x= secondstring[i];
            if(x>='a' && x<='z')
                arr[x - 'a']++;
            else if(x>='A' && x<='Z')
                arr[x-'A']++;
        }
        k=25;
        max_idx=-1;
        while(1)
        {
            maxm=-1;
            for(i=0;i<26;i++)
            {
                if(arr[i]>=maxm)
                {
                    maxm=arr[i];
                    max_idx=i;
                }
            }
            if(maxm==0)
                break;
            for(i=25;i>=0;i--)
            {
                if(arr[i]==maxm)
                {
                    arr[i]=0;
                    enc[i]=freq_seq[k];
                   // cout<<i<<" and "<<enc[i]<<endl;
                    k--;
                }
            }
        }

       /* for(i=0;i<26;i++)
        {
            printf("%c = %c\n",i+'a',enc[i]);
        }*/
        for(i=0;i<lc;i++)
        {
            x=secondstring[i];
            if(x>='a' && x<='z')
            {
                printf("%c",enc[x-'a']);
            }
            else if(x>='A' && x<='Z')
            {
                printf("%c",enc[x-'A']-32);
            }
            else
                printf("%c",x);
        }
        printf("\n");

    }


return 0;
}
